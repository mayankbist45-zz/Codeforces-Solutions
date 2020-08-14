#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int visited[maxn][maxn];
vector<string> v;

bool isValid(int x, int y) {
    return !(x < 0 or y < 0 or x >= n or y >= m);
}

void dfs(int i = 0, int j = 0) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        bool ans;
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValid(x, y) and !visited[x][y] and v[x][y] == '#') dfs(x, y);
    }
}

void solve() {
    cin >> n >> m;
    v = vector<string>(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    vector<int> col(m), row(n);
    int sum = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j = 0; j < m; j++) {
            if (ct and j > 0 and v[i][j] == '#' and v[i][j - 1] == '.') {
                cout << -1 << endl;
                return;
            }
            ct += v[i][j] == '#';
        }
        sum += ct == 0;
        row[i] = ct;
    }
    for (int i = 0; i < m; i++) {
        int ct = 0;
        for (int j = 0; j < n; j++) {
            if (ct and j > 0 and v[j][i] == '#' and v[j - 1][i] == '.') {
                cout << -1 << endl;
                return;
            }
            ct += v[j][i] == '#';
        }
        sum2 += ct == 0;
        col[i] = ct;
    }
    if ((sum and sum2 == 0) or (sum2 and sum == 0)) {
        cout << -1;
        return;
    }
    int ct = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] and v[i][j] == '#')dfs(i, j), ct++;
        }
    }
    cout << ct << endl;
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