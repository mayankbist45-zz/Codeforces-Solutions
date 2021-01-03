#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }
    int range = 1 << n;
    vector<bool> good(range, true);
    for (int mask = 0; mask < range; mask++) {
        for (int j = 0; j < n; j++) {
            if (!(mask >> j & 1))continue;
            for (int k = 0; k < n; k++) {
                if (!(mask >> k & 1))continue;
                if (j == k)continue;

                if (!g[j][k]) {
                    good[mask] = false;
                    break;
                }
            }
        }
    }
    vector<int> dp(range, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < range; mask++) {
        if (good[mask])dp[mask] = 1;
        else {
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                dp[mask] = min(dp[mask], dp[submask] + dp[submask ^ mask]);
            }
        }
    }

    cout << dp[range - 1] << endl;
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