#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 5010
const int MOD = 1000000007;

string a, b;
int n, m;
int dp[maxn][maxn];
int solve(int pos1, int pos2) {
    if (pos1 == n or pos2 == m)return 0;
    int &ans = dp[pos1][pos2];
    if (ans != -1)return ans;
    ans = 0;
    ans = max({ans, solve(pos1 + 1, pos2) - 1, solve(pos1, pos2 + 1) - 1});
    if (a[pos1] == b[pos2]) {
        ans = max({ans, 2 + solve(pos1 + 1, pos2 + 1)});
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cin >> a >> b;
    int ans = 0;
    solve(0, 0);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            ans = max(ans, dp[i][j]);
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