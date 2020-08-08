#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), b(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int mn1 = *min_element(v.begin(), v.end());
    int mn2 = *min_element(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tp = v[i] - mn1;
        int zp = b[i] - mn2;

        ans += max(tp, zp);
    }
    cout << ans << endl;
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