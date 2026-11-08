// Codeforces 2274B - Prefix
// Rating: 1100
// Tags:   greedy
// Link:   https://codeforces.com/problemset/problem/2274/B
// Idea:   brutal ass max min greedy

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
        int n{};
        cin>>n;

        long long hi = 0;
        long long lo = 0;
        long long best = -51;
        for (int i = 0; i < n; i++) {
            long long a; 
            cin >> a;
            best = max(best, a + max(abs(hi), abs(lo)));   
            long long newHi = max(a, a + 2 * hi);
            long long newLo = min(a, a + 2 * lo);
            hi = newHi;
            lo = newLo;
        }
        cout << best << '\n';
        
    }
}