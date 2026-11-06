#include <bits/stdc++.h>
using namespace std;

string replaceN(string n, int index, string k=""){
    k += n[0];
    for (int i = 1; i<n.size(); i++){
        if (i==index){
            if (n[i]=='0'){
                n[i]='1';
            }
            else {
                n[i]='0';
        
            }
        }
        if (n[i]==n[i-1]){
            continue;
        }
        k += n[i];
        
    }
    return k;
}
int findN(string n){
    int consecutive = 1;
    set<string> seen;
    seen.insert(replaceN(n, -1));
    for (int i = 1; i<n.size(); i++){
        if (n[i]==n[i-1]){
            consecutive+=1;
            if (consecutive ==3){
                seen.insert(replaceN(n, i-1));
            }
            continue;
        }

        if(consecutive==1&&i>1){
            seen.insert(replaceN(n, i-1));
        }
        consecutive = 1;
        
    }
    return static_cast<int>(seen.size());
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;  
    while (t--)
    {
        string n;
        cin >> n;
        cout << findN(n) << "!\n";
        
    }
}
