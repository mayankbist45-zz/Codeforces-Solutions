#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 80
const int MOD = 1000000007;

int n, m, k;
vector<vector<int>> v;
int dp[maxn][maxn][maxn][maxn];
int solve(int x, int y, int cnt, int rem) {
    if (x == n) {
        if (rem == 0)return 0;
        return INT_MIN;
    }
    int &ans = dp[x][y][cnt][rem];
    if (ans != -1)return ans;
    ans = 0;
    if (y + 1 < m) {
        ans = solve(x, y + 1, cnt, rem);
        if (cnt < m / 2)ans = max(ans, v[x][y] + solve(x, y + 1, cnt + 1, (rem + v[x][y]) % k));
    } else {
        ans = solve(x + 1, 0, 0, rem);
        if (cnt < m / 2)ans = max(ans, v[x][y] + solve(x + 1, 0, 0, (rem + v[x][y]) % k));
    }
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    v = vector<vector<int>>(n, vector<int>(m));
    for (auto &i: v)
        for (auto &j: i)cin >> j;
    cout << solve(0, 0, 0, 0) << endl;
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