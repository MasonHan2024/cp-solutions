# Competitive programming log

C++20 solutions to Codeforces problems ([mason_han](https://codeforces.com/profile/mason_han)).
Each row has the key idea in one line. Code is in [`solutions/`](solutions/).

**Solved:** 3  |  **By rating:** 800: 3

**By tag:** implementation: 2 · math: 2 · data structures: 1 · dfs and similar: 1 · dp: 1 · greedy: 1 · hashing: 1

| Date | Problem | Rating | Tags | Result | Tries | Key idea | Code |
|---|---|---|---|---|---|---|---|
| 2026-11-06 | [2276A Perfect Sandwiches](https://codeforces.com/problemset/problem/2276/A) | 800 | `greedy`, `math` | [✅ AC](https://codeforces.com/contest/2276/submission/397535668) | 1 | min(b, a-b): each sandwich needs 1 sausage and 1 extra cheese | [cpp](solutions/2276A.cpp) |
| 2026-11-06 | [2274A The Projections of Paco](https://codeforces.com/problemset/problem/2274/A) | 800 | `dfs and similar`, `dp`, `hashing`, `implementation`, `math` | [✅ AC](https://codeforces.com/contest/2274/submission/397539081) | 1 | undo the reflections backwards: cur = 2*a[i] - cur, answer is cur/2 | [cpp](solutions/2274A.cpp) |
| 2026-11-06 | [2275B Did Not Go to Print](https://codeforces.com/problemset/problem/2275/B) | 800 | `data structures`, `implementation` | [✅ AC](https://codeforces.com/contest/2275/submission/397537525) | 1 | stack: each 2 cancels the most recent unmatched 1; 3s and unmatched 2s are marked; print the unmarked | [cpp](solutions/2275B.cpp) |

Workflow: `./new.sh 2276A` → code → `./run.sh 2276A` → submit → `./ac.sh 2276A "idea"`.
