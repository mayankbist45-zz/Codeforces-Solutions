#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;


vector<int> g[maxn];
vector<int> dest, vis;

void dfs(int u, vector<int> &dist) {
    vis[u] = true;
    dest[u] = dist[u];
    for (auto x : g[u]) {
        if (!vis[x] and dist[u] < dist[x]) {
            dfs(x, dist);
        }
        if (dist[u] >= dist[x])dest[u] = min(dest[u], dist[x]);
        else dest[u] = min(dest[u], dest[x]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)g[i].clear();
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    dest = vector<int>(n + 1, INT_MAX);
    vis = vector<int>(n + 1, false);
    vector<int> dist(n + 1, -1);
    auto bfs = [&](int src) {
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto x : g[node])
                if (dist[x] == -1) {
                    dist[x] = 1 + dist[node];
                    q.push(x);
                }
        }
    };
    bfs(1);
    dfs(1, dist);
    for (int i = 1; i <= n; i++)
        cout << dest[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}