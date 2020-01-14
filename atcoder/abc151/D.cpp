#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 30

char mat[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[30][30];
int h, w;
int dist[maxn][maxn];

bool isValid(int a, int b) {
    return a >= 0 and a < h and b >= 0 and b < w;
}

int bfs(int a, int b) {
    memset(visited, false, sizeof visited);
    memset(dist, 0, sizeof dist);
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    dist[a][b] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (isValid(xx, yy) and !visited[xx][yy] and mat[xx][yy] == '.') {
                dist[xx][yy] = dist[x][y] + 1;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            ans = max(ans, dist[i][j]);
    return ans;
}

void solve() {
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == '.') {
                ans = max(ans, bfs(i, j));
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