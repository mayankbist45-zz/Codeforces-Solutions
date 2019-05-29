#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {

    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1), val(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> val[i];
    }
    int dp[n + 1][W + 1] = {};
    for (int i = 1; i <= n; i++) {
        for (int wt = 1; wt <= W; wt++) {
            if (w[i] <= wt)
                dp[i][wt] = max(dp[i - 1][wt], dp[i - 1][wt - w[i]] + val[i]);
            else
                dp[i][wt] = dp[i - 1][wt];
        }
    }
    cout << dp[n][W];
}

