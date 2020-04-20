#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int dp[2][110];

void solve() {
    int m;
    cin >> m;
    for (auto &i : dp) {
        for (int j = 0; j < m; j++) {
            cin >> i[j];
        }
    }
    dp[1][0] += dp[0][0];
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < m; j++) {
            int tp = dp[i][j];
            dp[i][j] = tp + dp[i][j - 1];
            if (i > 0)
                dp[i][j] = max(dp[i][j], tp + dp[i - 1][j]);
        }
    }
    cout << dp[1][m - 1] << endl;
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