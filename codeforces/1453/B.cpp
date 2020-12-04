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
    int op = 0;
    for (int i = n - 2; i >= 0; i--) {
        op += abs(v[i] - v[i + 1]);
    }
    int oop = op;
    for (int i = 0; i + 1 < n; i++) {
        int cur = oop - abs(v[i] - v[i + 1]);
        if (i != 0) {
            cur -= abs(v[i] - v[i - 1]);
            cur += abs(v[i - 1] - v[i + 1]);
        }
        op = min(op, cur);
    }
    op = min(op, oop - abs(v[n - 2] - v[n - 1]));
    cout << op << endl;
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