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
    int xr = 0;
    for (int i = 0; i < n; ++i) cin >> v[i], xr ^= v[i];

    if (n % 2 == 0 and xr != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> ans;
    for (int i = 0; i + 2 < n; i += 2) {
        ans.push_back({i + 1, i + 2, i + 3});
    }
    for (int i = 0; i + 2 < n; i += 2) {
        ans.push_back({i + 1, i + 2, n});
    }
    cout << "YES\n" << ans.size() << endl;
    for (auto &x: ans) {
        for (auto &j: x)
            cout << j << " ";
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