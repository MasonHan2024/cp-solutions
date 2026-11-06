# Competitive programming log

C++20 solutions to Codeforces problems ([mason_han](https://codeforces.com/profile/mason_han)).
Each row has the key idea in one line. Code is in [`solutions/`](solutions/).

**Solved:** 2  |  **By rating:** 800: 2

| Date | Problem | Rating | Result | Tries | Key idea | Code |
|---|---|---|---|---|---|---|
| 2026-11-06 | [2276A Perfect Sandwiches](https://codeforces.com/problemset/problem/2276/A) | 800 | [✅ AC](https://codeforces.com/contest/2276/submission/397535668) | 1 | min(b, a-b): each sandwich needs 1 sausage and 1 extra cheese | [cpp](solutions/2276A.cpp) |
| 2026-11-06 | [2274A The Projections of Paco](https://codeforces.com/problemset/problem/2274/A) | 800 | [✅ AC](https://codeforces.com/contest/2274/submission/397539081) | 1 | undo the reflections backwards: cur = 2*a[i] - cur, answer is cur/2 | [cpp](solutions/2274A.cpp) |

Workflow: `./new.sh 2276A` → code → `./run.sh 2276A` → submit → `./ac.sh 2276A "idea"`.
