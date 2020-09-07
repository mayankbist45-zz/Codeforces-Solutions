#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

int n, kk;
string a, b;

/*
 * dp[i][j][k] - no of seq by choosing i val from 1 string j no of b[0] and doing k steps
 */

int dp[maxn][maxn][maxn];

void max_self(int &a, int b) {
    a = max(a, b);
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> kk >> a >> b;

    dp[0][0][0] = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= kk; k++) {
                if (dp[i][j][k] == -1)continue;
                max_self(dp[i + 1][j + (a[i] == b[0])][k], dp[i][j][k] + (a[i] == b[1] ? j : 0));
                //change to b0
                max_self(dp[i + 1][j + 1][k + 1], dp[i][j][k] + (b[0] == b[1] ? j : 0));
                //change to b1
                max_self(dp[i + 1][j + (b[0] == b[1])][k + 1], dp[i][j][k] + j);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; j++)for (int steps = 0; steps <= kk; steps++)ans = max(ans, dp[a.size()][j][steps]);
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