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
        int a;
        string b;
        cin >> a >> b;

        vector<int> v(a, false);
        vector<int> st;

        for (int i=0; i<a;i++) {
            if (b[i]=='1'){
                st.push_back(i);
            }
            else if (b[i]=='2'){
                if(st.size()){
                    v[st.back()] = true;
                    st.pop_back();
                }
                else{
                    v[i] = true;
                }
            }
            else if (b[i] == '3'){
                v[i] = true;
            }
        }
        int count{0};
        string s;
        for (int i=0; i<a; i++){
            if (!v[i]){
                s += to_string(i+1) + " ";
                count ++;
           }
        }
        cout << count << '\n' << s << '\n';
    }
}
