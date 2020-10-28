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
    vector<vector<int>> dp(n + 1, vector<int>(410, 1e14));
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 400; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if (i != 0)
                dp[i][j] = min(dp[i][j], abs(v[i - 1] - j) + dp[i - 1][j - 1]);
        }
    }
    cout << dp[n][400] << endl;
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