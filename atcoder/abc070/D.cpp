#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<pair<int, int>> g[maxn];

void dijkstra(int src, vector<int> &dist) {
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
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int q, k;
    cin >> q >> k;
    vector<int> dist(n + 1, 1e15);
    dijkstra(k, dist);
    for(int i = 0; i < q;i++){
        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] << endl;
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