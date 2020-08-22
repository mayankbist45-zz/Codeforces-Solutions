#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;


int dist[maxn][maxn];
vector<string> v;
int h, w;
int ch, cw;
int dh, dw;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool valid(pair<int, int> a) {
    return !(a.first < 0 or a.second < 0 or a.first >= h or a.second >= w);
}


void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> st;
    dist[ch][cw] = 0;
    st.push({0, {ch, cw}});
    while (!st.empty()) {
        auto top = st.top();
        st.pop();

        int node_dist = top.first;
        auto node = top.second;

        if (node_dist != dist[node.first][node.second])continue;

        for (int i = 0; i < 4; i++) {
            pair<int, int> tp = {node.first + dx[i], node.second + dy[i]};
            if (valid({tp.first, tp.second}) and v[tp.first][tp.second] == '.') {
                if (dist[tp.first][tp.second] > node_dist) {
                    dist[tp.first][tp.second] = node_dist;
                    st.push({dist[tp.first][tp.second], {tp.first, tp.second}});
                }
            }
        }
        for (int i = -2; i <= 2; i++)
            for (int j = -2; j <= 2; j++) {
                if (i == 0 and j == 0)continue;
                pair<int, int> tp = {node.first + i, node.second + j};
                if (valid({tp.first, tp.second}) and v[tp.first][tp.second] == '.') {
                    if (dist[tp.first][tp.second] > 1 + node_dist) {
                        dist[tp.first][tp.second] = 1 + node_dist;
                        st.push({dist[tp.first][tp.second], {tp.first, tp.second}});
                    }
                }
            }
    }
}


void solve() {
    cin >> h >> w;

    cin >> ch >> cw;
    ch--, cw--;
    cin >> dh >> dw;
    dh--, dw--;

    v = vector<string>(h);
    for (int i = 0; i < h; i++)cin >> v[i];
    memset(dist, 63, sizeof dist);
    dijkstra();
    if (dist[dh][dw] > INT_MAX)cout << -1;
    else cout << dist[dh][dw];
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