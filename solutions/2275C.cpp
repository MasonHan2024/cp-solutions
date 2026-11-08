// Codeforces 2275C - Unrequited Love
// Rating: 1000
// Tags:   brute force, data structures
// Link:   https://codeforces.com/problemset/problem/2275/C
// Idea:   sums a[i]+a[i+2]-a[i+4]; count equal pairs with a counting array (+30000 offset), subtract j=i+2 and j=i+4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin >> t; 
    vector<int> cnt(60001,0);
    while (t--)
    { 
        int n{};
        cin >> n;
        vector<int> notes(n);
        for (int i =0; i<n; i++){
            cin >> notes[i];
        }
        vector<int> s(n-4);
        for (int i = 0; i < n-4; i++) s[i] = notes[i] + notes[i+2] - notes[i+4];
        long long pairs = 0;
        int tempCount{};
        for (int i =0; i<n-4; i++){
            tempCount = s[i]+30000;
            pairs+= cnt[tempCount];
            if (i>=2&& s[i] == s[i-2]){
                pairs -= 1;
            }
            if (i>=4&& s[i] == s[i-4]){
                pairs -= 1;
            }
            cnt[tempCount]++;
        }
        cout << pairs << '\n';
        for (int i:s) cnt[i+30000]=0;

    }
}