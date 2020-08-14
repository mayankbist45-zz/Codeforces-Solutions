#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<pair<int, int>> g[maxn];
int d1[maxn], in[maxn];

void dijkstra(int src, long long dist[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> st;
    dist[src] = 0;
    st.push({0, src});
    while (!st.empty()) {
        auto top = st.top();
        st.pop();
        int node_dist = top.first;
        int node = top.second;
        if (node_dist != dist[node])continue;
        for (auto x : g[node]) {
            auto dest = x.first;
            if (dist[dest] > node_dist + x.second) {
                dist[dest] = node_dist + x.second;
                st.push({dist[dest], dest});
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;

        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    vector<pair<int, int>> edge;
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        g[1].push_back({s, y});
        edge.push_back({s, y});
    }
    memset(d1, 63, sizeof d1);
    dijkstra(1, d1);
    cout << endl;
    for (int i = 1; i <= n; i++)
        for (auto x: g[i])if (x.second + d1[i] == d1[x.first])in[x.first]++;

    int ans = 0;
    for (auto x: edge) {
        if (d1[x.first] != x.second or in[x.first] > 1) {
            if (d1[x.first] == x.second)in[x.first]--;
            ans++;
        }
    }
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