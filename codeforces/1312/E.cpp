#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 510
const int MOD = 1000000007;

int dp[maxn][maxn], dp1[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    iota(dp1, dp1 + n + 1, 0ll);
    for (int gap = 0; gap < n; gap++)
        for (int i = 1; i <= n and i + gap <= n; i++)
            if (gap == 0)dp[i][i] = v[i];
            else for (int k = i; k < i + gap; k++)if (dp[i][k] != -1 and dp[i][k] == dp[k + 1][i + gap])dp[i][i + gap] = dp[i][k] + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[j][i] != -1)
                dp1[i] = min(dp1[i], dp1[j - 1] + 1);
        }
    }
    cout << min(n, dp1[n]) << endl;
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