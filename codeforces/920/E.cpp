#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

set<int> g[maxn];
vector<int> vis;
int n, m;

struct disjoint_set {
    vector<int> par, sz;
    disjoint_set(int n) : par(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0ll);
    }
    int find(int x) { return par[x] = (x == par[x] ? x : find(par[x])); }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

void dfs(int u, disjoint_set &dsu) {
    vis[u] = true;
    int asn = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i] and g[u].find(i) == g[u].end()) {
            dsu.unite(i, u);
            dfs(i, dsu);
        } else if (vis[i] and g[u].find(i) == g[u].end())
            dsu.unite(i, u);
}

void solve() {
    cin >> n >> m;
    vector<int> deg(n + 1, n - 1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        deg[a]--, deg[b]--;
        g[a].insert(b);
        g[b].insert(a);
    }
    disjoint_set dsu(n);
    vis = vector<int>(n + 1);
    int ct = 0, pre = -1;
    for (int i = 1; i <= n; i++)
        if (deg[i] >= n / 2) {
            if (pre == -1)pre = i;
            else dsu.unite(i, pre);
            vis[i] = 1;
        }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])dfs(i, dsu);
    }
    vector<int> ans;
    vis = vector<int>(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!vis[dsu.find(i)]){
            ans.push_back(dsu.sz[dsu.find(i)]);
            vis[dsu.find(i)] = 1;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x: ans)cout << x << " ";
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