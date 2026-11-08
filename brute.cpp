#include <bits/stdc++.h>
using namespace std;

vector<long long> a, cur, bestSeq;
long long best;

// i = index to decide, s = sum of a[0..i-1] after replacements, mx = max so far
void go(int i, long long s, long long mx) {
    if (i == (int)a.size()) {
        if (mx > best) { best = mx; bestSeq = cur; }
        return;
    }
    for (long long v : {a[i] - s, a[i], a[i] + s}) {
        cur.push_back(v);
        go(i + 1, s + v, max(mx, v));
        cur.pop_back();
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        a.assign(n, 0);
        for (auto& x : a) cin >> x;
        best = LLONG_MIN;
        cur = {a[0]};
        go(1, a[0], a[0]);
        cout << best << '\n';
        cerr << "best sequence:";
        for (long long x : bestSeq) cerr << ' ' << x;
        cerr << '\n';
    }
}




for i in $(seq 1 2000); do
    python3 gen.py $i > test.in
    ./fast  < test.in > fast.out
    ./brute < test.in > brute.out 2> path.txt
    if ! cmp -s fast.out brute.out; then
        echo "FAIL on seed $i"
        cat test.in
        echo "yours: $(cat fast.out)   correct: $(cat brute.out)"
        cat path.txt
        break
    fi
done