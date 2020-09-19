#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++) cin >> v[i].first >> v[i].second;

    vector<int> pre(n + 1), dp(n + 1);
    dp[1] = pre[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (auto x: v) {
            int l = x.first, h = x.second, mid, ans = -1;
            while (l <= h) {
                mid = l + h >> 1;
                if (i - mid >= 1)ans = mid, l = mid + 1;
                else h = mid - 1;
            }
            if (ans != -1)dp[i] += (pre[i - x.first] - pre[i - ans - 1] + MOD) % MOD;
            if (dp[i] >= MOD)dp[i] -= MOD;
        }
        pre[i] = dp[i] + pre[i - 1];
        if (pre[i] >= MOD)pre[i] -= MOD;
    }
    cout << dp[n] << endl;
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