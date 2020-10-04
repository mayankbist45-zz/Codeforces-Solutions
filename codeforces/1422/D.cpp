#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

const int64_t INF64 = int64_t(2e18) + 5;

struct Dijkstra {
    struct edge {
        int node = -1;
        int64_t weight = 0;

        edge() {}

        edge(int _node, int64_t _weight) : node(_node), weight(_weight) {}
    };

    struct state {
        int64_t dist;
        int node;

        state() {}

        state(int64_t _dist, int _node) : dist(_dist), node(_node) {}

        bool operator<(const state &other) const {
            return dist > other.dist;
        }
    };

    int n;
    vector<vector<edge>> adj;
    vector<int64_t> dist;
    vector<int> parent;

    Dijkstra(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
    }

    void add_directional_edge(int a, int b, int64_t weight) {
        adj[a].emplace_back(b, weight);
    }

    void add_bidirectional_edge(int a, int b, int64_t weight) {
//        debug2(a, b, weight);
        add_directional_edge(a, b, weight);
        add_directional_edge(b, a, weight);
    }

    void dijkstra_check(priority_queue<state> &pq, int node, int from, int64_t new_dist) {
        if (new_dist < dist[node]) {
            dist[node] = new_dist;
            parent[node] = from;
            pq.emplace(new_dist, node);
        }
    }

    void dijkstra(const vector<int> &source) {
        if (n == 0) return;
        dist.assign(n, INF64);
        parent.assign(n, -1);
        priority_queue<state> pq;

        for (int src : source)
            dijkstra_check(pq, src, -1, 0);

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();

            if (top.dist > dist[top.node])
                continue;

            for (edge &e : adj[top.node])
                dijkstra_check(pq, e.node, top.node, top.dist + e.weight);
        }
    }
};

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n, m;
    cin >> n >> m;

    int sx, sy;
    cin >> sx >> sy;

    int fx, fy;
    cin >> fx >> fy;

    Dijkstra dij(m + 2);
    vector<pair<pair<int, int>, int>> v(m);
    int s = m, f = m + 1;
    dij.add_directional_edge(s, f, dist({sx, sy}, {fx, fy}));
    for (int i = 0; i < m; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
        dij.add_directional_edge(s, v[i].second, min(abs(v[i].first.first - sx), abs(v[i].first.second - sy)));
        dij.add_directional_edge(v[i].second, f, dist(v[i].first, {fx, fy}));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < m; i++)
        dij.add_bidirectional_edge(v[i].second, v[i + 1].second, abs(v[i].first.first - v[i + 1].first.first));
    for (int i = 0; i < m; i++)swap(v[i].first.first, v[i].first.second);
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < m; i++)
        dij.add_bidirectional_edge(v[i].second, v[i + 1].second, abs(v[i].first.first - v[i + 1].first.first));
    dij.dijkstra({s});
    cout << dij.dist[f] << endl;
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