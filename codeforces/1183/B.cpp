#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int mx = 0, mn = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        v[i] += k;
    }
    if (mn + k < mx - k) {
        cout << -1 << endl;
        return;
    }
    cout << *min_element(v.begin(), v.end()) << endl;
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