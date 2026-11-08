// Codeforces 2276C - Subarrays
// Rating: 1100
// Tags:   math, number theory
// Link:   https://codeforces.com/problemset/problem/2276/C
// Idea:   counter problem, can counter a distance. got prefix sum hint

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
        int k{};
        cin>>k;
        vector<int> preSum(n+1, 0);
        vector<int> cnt(k,0);
        int temp{};
        int curSum {};
        long long subPairs = 0;
        for (int i = 1; i<n+1; i++){
            cin >> temp;
            curSum = (temp + preSum[i-1])%k;
            preSum[i] = curSum;
            if (i > k){
                cnt[preSum[i-k-1]]++;
                subPairs += cnt[curSum];
            }
        }
        cout << subPairs << '\n';
    }
}