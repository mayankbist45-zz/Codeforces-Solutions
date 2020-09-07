#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int pos = 0, neg = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0)pos += v[i];
        else if (v[i] < 0) {
            int tp = min(pos, abs(v[i]));
            v[i] -= tp;
            pos -= tp;
        }
    }
    cout << pos << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}