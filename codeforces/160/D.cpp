#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct disjoint_set {
    vector<int> par, cost, sz;
    disjoint_set(int n) : par(n + 1), cost(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0ll);
    }
    int find(int x) { return par[x] = (x == par[x] ? x : find(par[x])); }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

struct find_bridges {
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<bool> visited;
    vector<int> tin, low;
    int timer;
    unordered_set<int> st;

    find_bridges(int _n) : n(_n + 1), adj(_n + 1) {}

    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for (auto to : adj[v]) {
            if (to.first == p) continue;
            if (visited[to.first]) {
                low[v] = min(low[v], tin[to.first]);
            } else {
                dfs(to.first, v);
                low[v] = min(low[v], low[to.first]);
                if (low[to.first] > tin[v])
                    st.insert(to.second);
            }
        }
    }

    void init_bridge() {
        timer = 0;
        st.clear();
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 1; i < n; ++i) {
            if (!visited[i])
                dfs(i);
        }
    }
};

struct kruskal {
    int n;
    vector<pair<pair<int, int>, pair<int, int>>> edge;
    disjoint_set dsu;

    kruskal(int n, int m) : n(n + 1), dsu(n) {}

    void add_edge(int a, int b, int wt, int id) {
        edge.push_back({{a,  b},
                        {wt, id}});
    }

    vector<int> edge_contributions() {
        vector<int> sol(edge.size());
        sort(edge.begin(), edge.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<vector<pair<pair<int, int>, int>>> wts;
        int cur = -1;
        for (auto x: edge) {
            if (x.second.first > cur)cur = x.second.first, wts.emplace_back();
            wts.back().push_back({x.first, x.second.second});
        }
        for (auto &vec: wts) {
            unordered_map<int, int> mp;
            map<pair<int, int>, int> cnt;
            int id = 1;
            for (auto x: vec)
                if (dsu.find(x.first.first) == dsu.find(x.first.second))
                    sol[x.second] = -1;
                else {
                    int a = dsu.find(x.first.first);
                    int b = dsu.find(x.first.second);
                    if (!mp.count(a))mp[a] = id++;
                    if (!mp.count(b))mp[b] = id++;
                }
            find_bridges bridge(id - 1);
            set<int> not_bridge;
            for (auto x: vec) {
                if (dsu.find(x.first.first) == dsu.find(x.first.second))continue;
                int a = dsu.find(x.first.first);
                int b = dsu.find(x.first.second);

                if (cnt.count(minmax(mp[a], mp[b]))) {
                    not_bridge.insert(x.second);
                    not_bridge.insert(cnt[minmax(mp[a], mp[b])]);
                }
                bridge.adj[mp[a]].push_back({mp[b], x.second});
                bridge.adj[mp[b]].push_back({mp[a], x.second});
                cnt[minmax(mp[a], mp[b])] = x.second;
            }
            bridge.init_bridge();
            for (auto x: vec)
                dsu.unite(x.first.first, x.first.second);
            for (auto x: bridge.st)
                if (not_bridge.find(x) == not_bridge.end())sol[x] = 1;
        }
        return sol;
    }

    int mst() {
        sort(edge.begin(), edge.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        int ans = 0;
        for (int i = 0; i < n; i++)
            dsu.par[i] = i, dsu.sz[i] = 0;
        for (auto p : edge) {
            if (dsu.unite(p.first.first, p.first.second))
                ans += p.second.first;
        }
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    kruskal k(n, m);
    find_bridges bridge(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        k.add_edge(a, b, c, i);
    }
    vector<int> sol = k.edge_contributions();
    for (int i = 0; i < m; i++) {
        if (sol[i] == 1)cout << "any" << endl;
        else if (sol[i] == -1)cout << "none" << endl;
        else cout << "at least one" << endl;
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