#include <bits/stdc++.h>
using namespace std;

int countSandwiches(int a, int b, int sandwiches) {
    if (a <= b || a<2 || b<1) {
        if (sandwiches == 0)
            return -1;
        return sandwiches;
    }
    else {
        if (a-2>b-1 && a-2>=2 && b-1>=1) {
            return countSandwiches(a-2, b-1, sandwiches+1);

        }
        else {
            return sandwiches + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int sandwiches {0};

        cout << countSandwiches(a, b ,sandwiches) << '\n';

    }
}
