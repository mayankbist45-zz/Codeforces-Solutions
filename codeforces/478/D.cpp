#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int dp[maxn][2];
int r, g, h;

void solve() {
    cin >> r >> g;
    while (h * (h + 1) / 2 <= r + g)h++;
    h--;

    /*
     * dp[red][j]
     * dp[red][j] += dp[red - j][j - 1];
     * if(total - red >= j)
     * dp[red][j] += dp[red][j - 1];
     */
    dp[0][0] = dp[0][1] = 1;
    int cur = 1, t = (h + 1) * h / 2;
    for (int j = 1; j <= h; j++) {
        for (int i = 1; i <= r; i++) {
            dp[i][cur] = dp[i][1 - cur] + (i - j >= 0 ? dp[i - j][1 - cur] : 0);
            if (dp[i][cur] >= MOD)dp[i][cur] -= MOD;
        }
        cur ^= 1;
    }
    cur ^= 1;
    int ans = 0;
    for (int i = max(t - g, 0ll); i <= r; i++) {
        ans += dp[i][cur];
        if (ans >= MOD)ans -= MOD;
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