#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n), c(k + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i <= k; i++)cin >> c[i];
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        auto ct = lower_bound(v.begin(), v.end(), i);
        if (ct == v.end())continue;
        int id = ct - v.begin();
        ans = max(ans, (n - id + c[i] - 1) / c[i]);
    }
    vector<vector<int>> res(ans);
    for (int i = 0; i < v.size(); i++)res[i % ans].push_back(v[i]);
    cout << ans << endl;
    for (auto x: res) {
        cout << x.size() << " ";
        for (auto cur : x)cout << cur << " ";
        cout << endl;
    }
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