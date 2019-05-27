
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    int dp[W + 1][n + 1] = {};
    for (int wt = 1; wt <= W; wt++) {
        for (int i = 1; i <= n; i++) {
            if (w[i] <= wt)
                dp[wt][i] = max(dp[wt][i - 1], v[i] + dp[wt - w[i]][i - 1]);
            else
                dp[wt][i] = dp[wt][i-1];
        }
    }
    cout << dp[W][n];
    return 0;
}