#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int vis[maxn][maxn];
int ct[3];
int n, m;

bool valid(int x, int y) {
    return !(x <= 0 || y <= 0 || x > n || y > m);
}

void dfs(int x, int y, int c) {
    vis[x][y] = 1;
    ct[c + 1]++;
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2) {
            if (valid(x + i, y + 2 * j) and !vis[x + i][y + 2 * j])dfs(x + i, y + 2 * j, c ^ 1);
            if (valid(x + 2 * j, y + i) and !vis[x + 2 * j][y + i])dfs(x + 2 * j, y + i, c ^ 1);
        }
}

void solve() {
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                ct[1] = ct[2] = 0;
                dfs(i, j, 0);
                ans += max(ct[1], ct[2]);
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