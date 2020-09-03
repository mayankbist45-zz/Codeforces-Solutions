#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int sz[maxn], dp[maxn], n;
vector<int> g[maxn];

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs(x, u);
        sz[u] += sz[x];
        dp[u] += dp[x];
    }
    dp[u] += sz[u];
}

void change_root(int u, int v) {
    dp[u] -= dp[v];
    dp[u] -= sz[v];
    sz[u] -= sz[v];
    sz[v] += sz[u];
    dp[v] += sz[u];
    dp[v] += dp[u];
}

int ans = 0;

void walk(int u, int p = -1) {
    ans = max(ans, dp[u]);
    for (auto x: g[u]) {
        if (x == p) continue;
        change_root(u, x);
        walk(x, u);
        change_root(x, u);
    }
}

void solve() {
    cin >> n;

    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    walk(1);
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