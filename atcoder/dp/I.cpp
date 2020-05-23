#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<double> p(n);
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    for (int i = 0; i < n; i++)cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (j)dp[i][j] = dp[i - 1][j - 1] * p[i - 1];
            dp[i][j] += dp[i - 1][j] * (1 - p[i - 1]);
        }
    double ans = 0;
    for (int i = 0; i <= n; i++)
        if (i > n - i)ans += dp[n][i];
    cout << fixed << setprecision(12) << ans << endl;
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