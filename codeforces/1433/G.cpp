#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
const int INF = 1e14;

set<pair<int, int>> g1[maxn];
void dijkstra(int src, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> st;
    dist[src] = 0;
    st.push({0, src});
    while (!st.empty()) {
        auto top = st.top();
        st.pop();
        int node_dist = top.first, node = top.second;
        if (node_dist != dist[node])continue;
        for (auto x : g1[node]) {
            auto dest = x.first;
            if (dist[dest] > node_dist + x.second) {
                dist[dest] = node_dist + x.second;
                st.push({dist[dest], dest});
            }
        }
    }
}

void solve() {
    auto min_self = [](int &a, int b) { a = min(a, b); };
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        g1[a].insert({b, x});
        g1[b].insert({a, x});
        edges.push_back({{a, b}, x});
    }
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) dijkstra(i, dist[i]);
    vector<pair<int, int>> junc(k);
    int curans = 0;
    for (int i = 0; i < k; i++)cin >> junc[i].first >> junc[i].second, curans += dist[junc[i].first][junc[i].second];
    for (auto x: edges) {
        //let's put this one to 0
        vector<int> ans(k,INF);
        vector<vector<int>> curd(2, vector<int>(n + 1, INF));
        g1[x.first.first].erase({x.first.second, x.second});
        g1[x.first.second].erase({x.first.first, x.second});
        dijkstra(x.first.first, curd[0]);
        dijkstra(x.first.second, curd[1]);
        for (int i = 0; i < k; i++) {
            auto now = junc[i];
            min_self(ans[i], dist[now.first][now.second]);
            min_self(ans[i], curd[0][now.first] + curd[1][now.second]);
            min_self(ans[i], curd[1][now.first] + curd[0][now.second]);
        }
        g1[x.first.first].insert({x.first.second, x.second});
        g1[x.first.second].insert({x.first.first, x.second});
        curans = min(curans, accumulate(ans.begin(), ans.end(), 0ll));
    }
    cout << curans << endl;
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