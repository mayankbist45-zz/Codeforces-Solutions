#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> v(n + 1), c(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i + 1];
    }
    int ans = 0;
    vector<vector<int>> dp(n + 2, vector<int>(k + 10));
    for (int i = 1; i <= n; i++)dp[i][0] = 1;

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            c[i] += dp[i][j] * dp[i][k - j] % MOD;
            if (c[i] >= MOD)c[i] -= MOD;
        }
        ans = (ans + c[i] * v[i] % MOD);
        if (ans >= MOD)ans -= MOD;
    }

    for (int i = 0; i < q; ++i) {
        int id, x;
        cin >> id >> x;

        int val = (ans - c[id] * v[id] % MOD + MOD) % MOD;
        val += c[id] * x % MOD;
        if (val >= MOD)val -= MOD;

        ans = val;
        v[id] = x;
        cout << val << endl;
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