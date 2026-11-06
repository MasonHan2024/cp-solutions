// Codeforces 2274A - The Projections of Paco
// Rating: 800
// Tags:   dfs and similar, dp, hashing, implementation, math
// Link:   https://codeforces.com/problemset/problem/2274/A
// Idea:   undo the reflections backwards: cur = 2*a[i] - cur, answer is cur/2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        long long ans{0};
        for(int i=n-1; i>=0; i--){
            ans = 2*a[i] - ans;
        }
        cout << ans/2<< '\n';
    }
}
