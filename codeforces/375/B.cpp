#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<vector<int>> dp;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    dp = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0')continue;
            dp[i][j] = 1;
            if (j and v[i][j - 1] == '1')dp[i][j] += dp[i][j - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> val;
        for (int j = 0; j < n; j++)val.push_back(dp[j][i]);
        sort(val.rbegin(), val.rend());
        for (int j = 0; j < val.size(); j++)
            ans = max(ans, (j + 1) * val[j]);
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