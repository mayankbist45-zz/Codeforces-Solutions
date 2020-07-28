#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 3010
const int MOD = 1000000007;

int v[maxn];
int dp[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> v[i];
    for (int i = n; i >= 1; i--)
        for (int j = i; j <= n; j++) {
            if (i == j)dp[i][j] = v[i];
            else dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1]);
        }
    cout << dp[1][n] << endl;
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

