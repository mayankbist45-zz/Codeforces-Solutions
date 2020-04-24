#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int r, c;
char mat[1010][1010];
int dist[1010][1010];
bool visited[1010][1010];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
using pii = pair<int, int>;

bool valid(pii a) {
    return !(a.first < 0 or a.second < 0 or a.first >= r or a.second >= c);
}

void bfs(pii src) {
    memset(dist, -1, sizeof dist);
    queue<pii> q;
    q.push(src);
    dist[src.first][src.second] = 0;
    visited[src.first][src.second] = true;
    while (!q.empty()) {
        pii a = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pii tp = {a.first + dx[i], a.second + dy[i]};
            if (!visited[tp.first][tp.second] and valid({tp.first, tp.second}) and mat[tp.first][tp.second] == '.') {
                visited[tp.first][tp.second] = true;
                dist[tp.first][tp.second] = 1 + dist[a.first][a.second];
                q.push(tp);
            }
        }
    }
}


void solve() {
    cin >> r >> c;

    int wht = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == '.')
                wht++;
        }

    bfs({0, 0});
    if (dist[r - 1][c - 1] == -1)
        cout << -1;
    else {
        cout << wht - (dist[r - 1][c - 1] + 1) << endl;
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