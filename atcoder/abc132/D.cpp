#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

int dp[maxn][maxn];

int C(int n, int k) {
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    return dp[n][k];
}

void solve() {
    C(2000, 2000);
    int n, k;
    cin >> n >> k;

    int r = n - k;
    for (int i = 1; i <= k; i++) {
        int ans = dp[r + 1][i];
        ans = ans * dp[k - 1][i - 1] % MOD;
        cout << ans << endl;
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