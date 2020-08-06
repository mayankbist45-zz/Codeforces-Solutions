#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 5010
const int MOD = 1000000007;

int dp[maxn][maxn], pre[maxn][maxn];

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    //dp[i][j] -> represents no of ways to get at jth point using i steps
    //dp[0][a] -> 1

    // ans if sum of dp[k][i] for all i from 1 to 5000
    dp[0][a] = pre[0][a] = 1;
    for (int i = 1; i <= n; i++)pre[0][i] += pre[0][i - 1];
    for (int steps = 1; steps <= k; steps++) {
        for (int pos = 1; pos <= n; pos++) {
            if (pos < b) {
                int tp = (b - pos) / 2;
                if (abs(b - pos) % 2 == 0)tp--;
                (dp[steps][pos] += pre[steps - 1][pos + tp]) %= MOD;
            } else if (pos > b) {
                int tp = (pos - b) / 2;
                if (abs(b - pos) % 2 == 0)tp--;
                dp[steps][pos] += (pre[steps - 1][n] - pre[steps - 1][pos - tp - 1] + MOD) % MOD;
            }

            int removal = (pre[steps - 1][pos] - pre[steps - 1][pos - 1] + MOD) % MOD;
            dp[steps][pos] -= removal;
            dp[steps][pos] += MOD;
            dp[steps][pos] %= MOD;
            pre[steps][pos] = (dp[steps][pos] + pre[steps][pos - 1]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)(ans += dp[k][i]) %= MOD;
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