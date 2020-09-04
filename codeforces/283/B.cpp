#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int v[maxn], dp[maxn][2], vis[maxn][2], n;

int dfs(int u, int f) {
    if (u <= 0 or u > n)return 0;
    if (vis[u][f])return dp[u][f];
    vis[u][f] = 1;
    return dp[u][f] = ((f == 1) ? v[u] + dfs(u + v[u], 0) : v[u] + dfs(u - v[u], 1));
}

void solve() {
    memset(dp, 63, sizeof dp);
    int mx = dp[0][0];
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        int inity = i;
        int initx = i + 1;
        int val = dfs(initx, 0) + inity;
        if (val >= mx)cout << -1 << endl;
        else cout << val << endl;
    }
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