#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;
const vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(1030, vector<int>(11, LLONG_MAX));
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 0; (k + 1) <= i; k++) {
                if (i % (k + 1) or dp[i / (k + 1)][j - 1] == LLONG_MAX)continue;
                int val = pow(prime[j - 1], k) * dp[i / (k + 1)][j - 1];
                if (val < 0 or val > 1e18)break;
                dp[i][j] = min(dp[i][j], val);
            }
        }
    }
    int ans = LLONG_MAX;
    for (int j = 0; j <= 10; j++) {
        ans = min(ans, dp[n][j]);
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