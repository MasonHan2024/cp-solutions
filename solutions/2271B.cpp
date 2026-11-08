// Codeforces 2271B - MEX Game
// Rating: 1000
// Tags:   games
// Link:   https://codeforces.com/problemset/problem/2271/B
// Idea:   heuristic just start counting from lowest integer odd win even lose, above keep going


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
        vector<int> cards(n);
        vector<int> cnt(2e+5,0);
        for (int i =0; i<n;++i){
            cin >>cards[i];
        }
        for (int i =0; i<n;++i){
            cnt[cards[i]]++;
        }
        for (int i=0; i<n; ++i){
            if (cnt[i]==2*k-1){
                cout << "YES\n";
                break;
            } else if(cnt[i]<2*k-1){
                cout << "NO\n";
                break;
            }
        }
    }
}