#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int visited[maxn];
vector<int> g[maxn];
int tin[maxn], low[maxn];
set<pair<int, int>> bridge;
int timer = 0;

void dfs(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    visited[u] = true;
    for (auto x : g[u]) {
        if (x == p)continue;
        if (!visited[x]) {
            dfs(x, u);
            low[u] = min(low[x], low[u]);
            if (low[x] > tin[u]) {
                bridge.insert({min(u, x), max(u, x)});
            }
        } else low[u] = min(low[u], tin[x]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(1);
    cout << bridge.size() << endl;
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