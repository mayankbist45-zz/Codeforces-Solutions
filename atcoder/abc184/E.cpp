#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;


int dist[maxn][maxn];
char v[maxn][maxn];
int h, w;
int ch, cw;
int dh, dw;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
vector<int> teleports[26];

bool valid(pair<int, int> a) {
    return !(a.first < 0 or a.second < 0 or a.first >= h or a.second >= w);
}

unordered_map<char, bool> done;
void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> st;
    dist[ch][cw] = 0;
    st.push({0, {ch, cw}});
    while (!st.empty()) {
        auto top = st.top();
        st.pop();

        int node_dist = top.first;
        auto node = top.second;

        if (node.first == dh and node.second == dw) {
            return;
        }

        if (node_dist != dist[node.first][node.second])continue;

        char curTeleport = v[node.first][node.second];
        if (isalpha(curTeleport) and islower(curTeleport) and !done[curTeleport]) {
            done[curTeleport] = true;
            for (int i = 0; i < teleports[curTeleport - 'a'].size(); i += 2) {
                pair<int, int> x = {teleports[curTeleport - 'a'][i], teleports[curTeleport - 'a'][i + 1]};
                if (dist[x.first][x.second] > 1 + node_dist) {
                    dist[x.first][x.second] = 1 + node_dist;
                    st.push({dist[x.first][x.second], {x.first, x.second}});
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> tp = {node.first + dx[i], node.second + dy[i]};
            if (valid({tp.first, tp.second}) and v[tp.first][tp.second] != '#') {
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
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
            if (v[i][j] == '#')continue;
            else if (v[i][j] == 'S')ch = i, cw = j;
            else if (v[i][j] == 'G')dh = i, dw = j;
            else if (isalpha(v[i][j]))teleports[v[i][j] - 'a'].push_back(i), teleports[v[i][j] - 'a'].push_back(j);
        }
    }
    for (int i = 0; i < maxn; i++)for (int j = 0; j < maxn; j++)dist[i][j] = INT_MAX;
    dijkstra();
    if (dist[dh][dw] == INT_MAX)cout << -1;
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