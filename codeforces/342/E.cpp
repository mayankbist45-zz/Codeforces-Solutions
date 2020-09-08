#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


struct lca_lift {
    const int lg = 24;
    int n;
    vector<int> depth;
    vector<vector<int> > edges;
    vector<vector<int> > lift;

    void init(int sz) {
        n = sz;
        depth = vector<int>(n);
        edges = vector<vector<int> >(n, vector<int>());
        lift = vector<vector<int> >(n, vector<int>(lg, -1));
    }

    void edge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void attach(int node_to_attach, int node_to_attach_to) {
        int a = node_to_attach, b = node_to_attach_to;
        edge(a, b);

        lift[a][0] = b;

        for (int i = 1; i < lg; i++) {
            if (lift[a][i - 1] == -1) lift[a][i] = -1;
            else lift[a][i] = lift[lift[a][i - 1]][i - 1];
        }

        depth[a] = depth[b] + 1;
    }

    void init_lift(int v = 1) {
        depth[v] = 0;
        dfs(v, -1);
    }

    void dfs(int v, int par) {
        lift[v][0] = par;

        for (int i = 1; i < lg; i++) {
            if (lift[v][i - 1] == -1) lift[v][i] = -1;
            else lift[v][i] = lift[lift[v][i - 1]][i - 1];
        }

        for (int x: edges[v]) {
            if (x != par) {
                depth[x] = depth[v] + 1;
                dfs(x, v);
            }
        }
    }

    int get(int v, int k) {
        for (int i = lg - 1; i >= 0; i--) {
            if (v == -1) return v;
            if ((1 << i) <= k) {
                v = lift[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }

    int get_lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int d = depth[a] - depth[b];
        int v = get(a, d);
        if (v == b) {
            return v;
        } else {
            for (int i = lg - 1; i >= 0; i--) {
                if (lift[v][i] != lift[b][i]) {
                    v = lift[v][i];
                    b = lift[b][i];
                }
            }
            return lift[b][0];
        }
    }

    int get_dist(int a, int b) {
        int v = get_lca(a, b);
        return depth[a] + depth[b] - 2 * depth[v];
    }
};

struct centroid {
    vector<vector<int>> edges;
    vector<bool> vis;
    vector<int> par, sz;

    int n;

    void init(int s) {
        n = s;
        edges = vector<vector<int>>(n, vector<int>());
        vis = vector<bool>(n, 0);
        par = sz = vector<int>(n);
    }

    void edge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int find_size(int u, int p = -1) {
        if (vis[u])return 0;
        sz[u] = 1;
        for (auto x: edges[u]) {
            if (x == p)continue;
            sz[u] += find_size(x, u);
        }
        return sz[u];
    }

    int find_centroid(int u, int p, int n) {
        for (auto x:edges[u]) {
            if (x == p)continue;
            if (!vis[x] and sz[x] > n / 2)return find_centroid(x, u, n);
        }
        return u;
    }

    void init_centroid(int u = 1, int p = -1) {
        find_size(u);
        int c = find_centroid(u, -1, sz[u]);
        vis[c] = true;
        par[c] = p;

        for (auto x: edges[c]) {
            if (!vis[x])init_centroid(x, c);
        }
    }
};

int best[maxn];
centroid c;
lca_lift lca;

void update(int p) {
    best[p] = 0;
    int cur = p;
    while (c.par[cur] != -1) {
        cur = c.par[cur];
        best[cur] = min(best[cur], lca.get_dist(p, cur));
    }
}

int query(int u) {
    int ans = best[u];
    int cur = u;
    while (c.par[cur] != -1) {
        cur = c.par[cur];
        ans = min(ans, best[cur] + lca.get_dist(u, cur));
    }
    return ans;
}

void solve() {
    memset(best, 63,sizeof best);
    int n, m;
    cin >> n >> m;

    c.init(n + 1), lca.init(n + 1);
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        c.edge(a, b);
        lca.edge(a, b);
    }
    c.init_centroid();
    lca.init_lift();
    update(1);
    for (int i = 0; i < m; i++) {
        int t, v;
        cin >> t >> v;

        if (t == 1)update(v);
        else cout << query(v) << endl;
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