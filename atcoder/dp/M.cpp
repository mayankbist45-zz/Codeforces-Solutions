#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int v[maxn];
int dp[110][maxn], pref[110][maxn];
int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)cin >> v[i];

    for (int i = 0; i <= n; i++)dp[i][0] = 1, pref[i][0] = 1;
    for (int i = 0; i <= k; i++)pref[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int val = pref[i - 1][j];
            if (j - v[i] >= 1)val -= pref[i - 1][j - v[i] - 1];
            val = (val + MOD) % MOD;
            (dp[i][j] += val) %= MOD;
            if (j)
                pref[i][j] = pref[i][j - 1] + dp[i][j], pref[i][j] %= MOD;
        }
    }
    cout << dp[n][k] << endl;
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

