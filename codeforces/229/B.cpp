#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
const int inf = 1e14;

vector<pair<int, int>> g1[maxn];
vector<int> tme[maxn];
int n, m;

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

        int add = 0;
        if (!tme[node].empty()) {
            auto tp = lower_bound(tme[node].begin(), tme[node].end(), node_dist);
            if (*tp == node_dist) {
                int id = tp - tme[node].begin(), val = *tp;
                while (id < tme[node].size() and tme[node][id] == val)add++, val++, id++;
            }
        }

        for (auto x : g1[node]) {
            auto dest = x.first;
            if (dist[dest] > add + node_dist + x.second) {
                dist[dest] = add + node_dist + x.second;
                st.push({dist[dest], dest});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        g1[a].push_back({b, c});
        g1[b].push_back({a, c});
    }
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        tme[i + 1].push_back(-1);
        for (int j = 0, tp; j < k; j++)cin >> tp, tme[i + 1].push_back(tp);
        tme[i + 1].push_back(1e14);
    }
    vector<int> dist(n + 1, inf);
    dijkstra(1, dist);
    if (dist[n] == inf)cout << -1 << endl;
    else cout << dist[n] << endl;
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