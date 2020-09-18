#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct disjoint_set {
    vector<int> par, cost, sz, sum;
    int comp;
    vector<pair<int, int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    disjoint_set(int n) : comp(n), par(n + 1), cost(n + 1), sum(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0ll);
    }
    int find(int x) { return par[x] = (x == par[x] ? x : find(par[x])); }
    void unite(int u, int v, int w) {
        u = find(u), v = find(v);
        if (u == v) {
            sum[u] += w;
            return;
        }
        comp--;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sum[u] += sum[v] + w;
        sz[u] += sz[v];
    }
    bool doshit(int need, int times) {
        if (comp < need)return false;
        vector<int> vis(par.size());
        for (int i = 1; i < par.size(); i++) {
            if (vis[find(i)])continue;
            pq.push({sum[find(i)], i});
            vis[find(i)] = 1;
        }
        while (pq.size() > need and times--) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            int val = min((int) 1e9, a.first + b.first + 1);
            res.push_back({find(a.second), find(b.second)});
            unite(a.second, b.second, val);
            pq.push({sum[find(a.second)], find(a.second)});
        }
        for (int i = 1; i < par.size(); i++) {
            if (i != find(i) and sz[find(i)] > 1) {
                while (times > 0)
                    times--, res.push_back({i, find(i)});
                break;
            }
        }
        return pq.size() == need and times == 0;
    }
};

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    disjoint_set dsu(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        dsu.unite(a, b, c);
    }
    if (dsu.doshit(q, p)) {
        cout << "YES" << endl;
        for (auto x: dsu.res)cout << x.first << " " << x.second << endl;
    } else cout << "NO" << endl;
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