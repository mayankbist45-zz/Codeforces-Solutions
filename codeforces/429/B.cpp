#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int v[maxn][maxn];
int dp1[maxn][maxn], dp2[maxn][maxn];
int dp3[maxn][maxn], dp4[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)cin >> v[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = v[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; ++j)
            dp2[i][j] = v[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; --j)
            dp3[i][j] = v[i][j] + max(dp3[i - 1][j], dp3[i][j + 1]);
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = v[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
    int ans = 0;
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++) {
            //left
            ans = max(ans, dp1[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1]);
            //top
            ans = max(ans, dp1[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j]);
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