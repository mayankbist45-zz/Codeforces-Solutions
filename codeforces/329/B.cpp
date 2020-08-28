#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int r, c;
int dist[1010][1010];

vector<string> v;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int len = 0;

bool valid(pair<int, int> a) { return !(a.first < 0 or a.second < 0 or a.first >= r or a.second >= c); }

void bfs(pair<int, int> src) {
    memset(dist, -1, sizeof dist);
    queue<pair<int, int>> q;
    q.push(src);
    dist[src.first][src.second] = 0;
    while (!q.empty()) {
        pair<int, int> a = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> tp = {a.first + dx[i], a.second + dy[i]};
            if (valid({tp.first, tp.second}) and v[tp.first][tp.second] != 'T' and dist[tp.first][tp.second] == -1) {
                dist[tp.first][tp.second] = 1 + dist[a.first][a.second];
                q.push(tp);
            }
        }
    }
}


void solve() {
    cin >> r >> c;
    v = vector<string>(r);
    for (int i = 0; i < r; ++i) cin >> v[i];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (v[i][j] == 'E')
                bfs({i, j});

    int val, ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (v[i][j] == 'S')val = dist[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (isdigit(v[i][j])) {
                if (dist[i][j] <= val and dist[i][j] != -1)ans += v[i][j] - '0';
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