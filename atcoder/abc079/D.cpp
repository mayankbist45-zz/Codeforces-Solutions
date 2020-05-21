#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

int c[10][10], m[maxn][maxn],dist[11];

vector<pair<int, int>> g1[maxn];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> st;
    dist[src] = 0;
    st.push({0, src});
    while (!st.empty()) {
        auto top = st.top();
        st.pop();

        int node_dist = top.first;
        int node = top.second;

        if (node_dist != dist[node])continue;

        for (int i = 0; i <= 9; i++) {
            auto dest = i;
            if (dest == node)continue;
            if (dist[dest] > node_dist + c[dest][node]) {
                dist[dest] = node_dist + c[dest][node];
                st.push({dist[dest], dest});
            }
        }
    }
}


void solve() {
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> c[i][j];
    memset(dist, 63, sizeof dist);
    dijkstra(1);
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
            if (m[i][j] == -1)continue;
            ans += dist[m[i][j]];
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