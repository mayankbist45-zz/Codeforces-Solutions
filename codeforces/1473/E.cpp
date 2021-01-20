#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<int, int>> g[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(2, vector<int>(2, 1e14)));
    function<void(int)> dijkstra = [&](int src) {
        using data = pair<int, tuple<int, int, int>>;
        priority_queue<data, vector<data>, greater<>> st;
        dist[src][0][0] = 0;

        st.push({0, {src, 0, 0}});
        while (!st.empty()) {
            auto top = st.top();
            st.pop();

            int node_dist = top.first;
            auto[node, max_bool, min_bool] = top.second;
            if (node_dist != dist[node][max_bool][min_bool])continue;

            for (auto x : g[node]) {
                auto dest = x.first;
                for (int i = 0; i <= 1 - max_bool; i++) {
                    for (int j = 0; j <= 1 - min_bool; j++) {
                        auto &cur_dest = dist[dest][i | max_bool][j | min_bool];

                        int del = (1 - i + j) * x.second;

                        if (cur_dest > dist[node][max_bool][min_bool] + del) {
                            cur_dest = dist[node][max_bool][min_bool] + del;
                            st.push({cur_dest, {dest, max_bool | i, j | min_bool}});
                        }
                    }
                }
            }
        }
    };
    dijkstra(0);
    for (int i = 1; i < n; i++)cout << dist[i][1][1] << " ";
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