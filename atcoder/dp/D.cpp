
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    cin >> n >> W;

    int w[n], val[n];

    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> val[i];
    }

    int dp[n + 1][W + 1] = {};

    for (int i = 1; i <= n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            dp[i][wt] = dp[i - 1][wt];
            if (wt - w[i - 1] >= 0)
                dp[i][wt] = max(val[i - 1] + dp[i-1][wt - w[i - 1]], dp[i][wt]);
        }
    }
    cout << dp[n][W];
    return 0;
}