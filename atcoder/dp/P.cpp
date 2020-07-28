#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
vector<vector<int>> dp;
//wb
void dfs(int u, int p = -1) {
    for (auto x: g[u])
        if (x != p) {
            dfs(x, u);
            dp[u][0] *= (dp[x][0] + dp[x][1]);
            dp[u][0] %= MOD;
            dp[u][1] *= dp[x][0];
            dp[u][1] %= MOD;
        }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp = vector<vector<int>>(n + 1, vector<int>(2, 1));
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
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