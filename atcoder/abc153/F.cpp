#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, d, a;
    cin >> n >> d >> a;

    vector<pair<int, int>> v(n);
    vector<int> c(n);
    int ans = 0;
    for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n and v[j].first <= v[i].first + 2 * d)j++;
        int nd = max(0ll, (v[i].second - c[i] * a + a - 1) / a);
        c[i] += nd;
        c[j] -= nd;
        c[i + 1] += c[i];
        ans += nd;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}