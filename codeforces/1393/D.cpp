#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

int dp1[maxn][maxn], dp2[maxn][maxn], dp3[maxn][maxn], dp4[maxn][maxn];
int n, m;
char v[maxn][maxn];

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> v[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = 1;
            if (v[i][j - 1] == v[i - 1][j] and v[i - 1][j] == v[i][j])dp1[i][j] += min(dp1[i - 1][j], dp1[i][j - 1]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--) {
            dp2[i][j] = 1;
            if (v[i][j + 1] == v[i - 1][j] and v[i - 1][j] == v[i][j])dp2[i][j] += min(dp2[i - 1][j], dp2[i][j + 1]);
        }
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++) {
            dp3[i][j] = 1;
            if (v[i][j - 1] == v[i + 1][j] and v[i + 1][j] == v[i][j])dp3[i][j] += min(dp3[i + 1][j], dp3[i][j - 1]);
        }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--) {
            dp4[i][j] = 1;
            if (v[i][j + 1] == v[i + 1][j] and v[i + 1][j] == v[i][j])dp4[i][j] += min(dp4[i + 1][j], dp4[i][j + 1]);
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += min({dp1[i][j], dp2[i][j], dp3[i][j], dp4[i][j]});
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