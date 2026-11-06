#!/usr/bin/env python3
"""Log a Codeforces problem you submitted: fetch the verdict from the public
Codeforces API, file the solution under solutions/, rebuild README.md, commit, push.

usage: ./ac.sh 2276A "min(b, a-b): each sandwich eats 1 sausage and 1 spare cheese"
"""
import datetime
import json
import pathlib
import re
import shutil
import subprocess
import sys
import urllib.request

HANDLE = "mason_han"
ROOT = pathlib.Path(__file__).resolve().parent.parent
SOL_DIR = ROOT / "solutions"
LOG = ROOT / "log.jsonl"

VERDICT = {
    "OK": "✅ AC", "WRONG_ANSWER": "❌ WA", "TIME_LIMIT_EXCEEDED": "⏱ TLE",
    "MEMORY_LIMIT_EXCEEDED": "💾 MLE", "RUNTIME_ERROR": "💥 RE",
    "COMPILATION_ERROR": "🛠 CE", "TESTING": "⏳ testing",
}


def fetch_submissions():
    url = f"https://codeforces.com/api/user.status?handle={HANDLE}&from=1&count=200"
    req = urllib.request.Request(url, headers={"User-Agent": "cp-log-script"})
    with urllib.request.urlopen(req, timeout=20) as r:
        data = json.load(r)
    if data.get("status") != "OK":
        sys.exit("Codeforces API error: " + str(data.get("comment")))
    return data["result"]  # newest first


def load_log():
    if not LOG.exists():
        return []
    return [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()]


def save_log(entries):
    LOG.write_text("".join(json.dumps(e, ensure_ascii=False) + "\n" for e in entries))


def build_readme(entries):
    solved = [e for e in entries if e["verdict"] == "OK"]
    by_rating = {}
    for e in solved:
        by_rating[e.get("rating") or "?"] = by_rating.get(e.get("rating") or "?", 0) + 1
    ratings = " · ".join(f"{k}: {v}" for k, v in sorted(by_rating.items(), key=lambda kv: str(kv[0])))

    lines = [
        "# Competitive programming log",
        "",
        f"C++20 solutions to Codeforces problems ([{HANDLE}](https://codeforces.com/profile/{HANDLE})).",
        "Each row has the key idea in one line. Code is in [`solutions/`](solutions/).",
        "",
        f"**Solved:** {len(solved)}  |  **By rating:** {ratings or '—'}",
        "",
        "| Date | Problem | Rating | Result | Tries | Key idea | Code |",
        "|---|---|---|---|---|---|---|",
    ]
    for e in sorted(entries, key=lambda e: e["date"], reverse=True):
        c, i = e["contest"], e["index"]
        prob = f"[{e['pid']} {e['name']}](https://codeforces.com/problemset/problem/{c}/{i})"
        res = f"[{VERDICT.get(e['verdict'], e['verdict'])}](https://codeforces.com/contest/{c}/submission/{e['sub_id']})"
        code = f"[cpp](solutions/{e['pid']}.cpp)" if e.get("has_code") else "—"
        idea = (e.get("idea") or "").replace("|", "\\|")
        lines.append(f"| {e['date']} | {prob} | {e.get('rating') or '?'} | {res} | {e['tries']} | {idea} | {code} |")
    lines += ["", "Workflow: `./new.sh 2276A` → code → `./run.sh 2276A` → submit → `./ac.sh 2276A \"idea\"`.", ""]
    (ROOT / "README.md").write_text("\n".join(lines))


def git(*args):
    return subprocess.run(["git", "-C", str(ROOT), *args], capture_output=True, text=True)


def main():
    if len(sys.argv) < 2:
        sys.exit('usage: ./ac.sh 2276A "key idea in one line"')
    pid = sys.argv[1]
    rest = sys.argv[2:]
    # optional: a .cpp filename anywhere after the id = the file to take the code from
    src_arg = next((a for a in rest if a.endswith(".cpp")), None)
    idea = " ".join(a for a in rest if a != src_arg).strip()
    m = re.fullmatch(r"(\d+)([A-Za-z]\d?)", pid)
    if not m:
        sys.exit(f"'{pid}' doesn't look like a problem id (expected e.g. 2276A or 1850B1)")
    contest, index = int(m[1]), m[2].upper()

    subs = [s for s in fetch_submissions()
            if s["problem"].get("contestId") == contest and s["problem"]["index"] == index]
    if not subs:
        sys.exit(f"No Codeforces submission for {contest}{index} by {HANDLE} yet. Submit it first, then rerun.")
    accepted = next((s for s in subs if s.get("verdict") == "OK"), None)
    best = accepted or subs[0]
    p = best["problem"]

    src = ROOT / (src_arg or f"{pid}.cpp")
    dst = SOL_DIR / f"{pid}.cpp"
    SOL_DIR.mkdir(exist_ok=True)
    if src_arg and not src.exists():
        sys.exit(f"{src_arg} not found in {ROOT}")
    if src.exists():
        shutil.move(str(src), dst)
        stem = src.stem
        for extra in (ROOT / f"{stem}.in", ROOT / stem):
            if extra.exists():
                extra.unlink()

    entry = {
        "pid": pid, "contest": contest, "index": index, "name": p.get("name", ""),
        "rating": p.get("rating"), "tags": p.get("tags", []),
        "verdict": best.get("verdict", "TESTING"), "tries": len(subs),
        "sub_id": best["id"], "idea": idea,
        "date": datetime.date.today().isoformat(), "has_code": dst.exists(),
    }
    entries = [e for e in load_log() if e["pid"] != pid] + [entry]
    save_log(entries)
    build_readme(entries)

    print(f"{pid} {entry['name']} | rating {entry['rating'] or '?'} | "
          f"{VERDICT.get(entry['verdict'], entry['verdict'])} after {entry['tries']} tries")

    if not (ROOT / ".git").exists():
        print("Logged locally (no git repo yet).")
        return
    git("add", "-A")
    msg = f"{pid} {entry['name']} ({VERDICT.get(entry['verdict'], entry['verdict'])})"
    if idea:
        msg += f": {idea}"
    r = git("commit", "-m", msg)
    if r.returncode != 0:
        print(r.stdout.strip() or r.stderr.strip())
        return
    if git("remote").stdout.strip():
        r = git("push")
        print("Pushed to GitHub." if r.returncode == 0 else "Commit made, but push failed:\n" + r.stderr.strip())
    else:
        print("Committed locally (no GitHub remote yet).")


if __name__ == "__main__":
    main()
