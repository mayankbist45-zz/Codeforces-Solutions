#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i + 1];
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (1 + i - v[i]) % MOD;
        for (int j = v[i]; j < i; j++) {
            dp[i] += dp[j];
            if (dp[i] >= MOD)dp[i] -= MOD;
        }
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
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