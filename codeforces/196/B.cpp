#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 1501
const int MOD = 1000000007;
#define inf make_pair(INT_MAX, INT_MAX)

int n, m;
pair<int, int> used[maxn][maxn];
int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

void solve() {
    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> s;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            used[i][j] = inf;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < v[i].size(); j++)
            if (v[i][j] == 'S') s = {i, j};
    }
    queue<int> q;
    q.push(s.first);
    q.push(s.second);
    used[s.first][s.second] = s;
    while (!q.empty()) {
        int x = q.front(); q.pop(); int y = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            int sx = (nx % n + n) % n, sy = (ny % m + m) % m;
            if (v[sx][sy] == '#')continue;
            if (used[sx][sy] == inf) {
                used[sx][sy] = make_pair(nx, ny);
                q.push(nx);
                q.push(ny);
            } else if (used[sx][sy] != make_pair(nx, ny)) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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