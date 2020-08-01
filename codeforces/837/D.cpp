#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int v[maxn], two[maxn], five[maxn];
int dp[2][210][5001];

int getP(int n, int di) {
    int ct = 0;
    while (n % di == 0)ct++, n /= di;
    return ct;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, sz;
    cin >> n >> sz;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        two[i] = getP(v[i], 2);
        five[i] = getP(v[i], 5);
    }
    /*
     * dp[i][j][k] -> max no of two we can get from using j elements till
     * position i with k no of 5's in the subset
     *
     * dp[i][j][k] = dp[i - 1][j][k]
     * dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j-1][k-five[i]])
     *
     * can optimise space for first state
     */
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sz; j++) {
            if (j)
                dp[i % 2][j][five[i]] = two[i];
            for (int k = 0; k <= 5000; k++) {
                dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j][k]);
                if (k - five[i] >= 0 and j - 1 >= 0 and dp[(i + 1) % 2][j - 1][k - five[i]] != -1)
                    dp[i % 2][j][k] = max(dp[i % 2][j][k], two[i] + dp[(i + 1) % 2][j - 1][k - five[i]]);
                if (dp[i % 2][j][k] != -1 and j == sz)
                    ans = max(ans, min(k, dp[i % 2][j][k]));
            }
        }
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