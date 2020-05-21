#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n), s(m);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < m; i++)cin >> s[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i - 1] == s[j - 1])dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + 1) % MOD;
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + MOD) % MOD;
        }
    }
    cout << (dp[n][m] + 1) % MOD << endl;
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

