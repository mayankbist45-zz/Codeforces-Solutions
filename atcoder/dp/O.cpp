#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 22
const int MOD = 1000000007;

int v[maxn][maxn], n, dp[maxn][(1 << 21)];

int solve(int pos, int mask) {
    if (pos == n)return 1;
    int &ans = dp[pos][mask];
    if (ans != -1)return ans;
    ans = 0;
    for (int i = 0; i < n; i++)
        if (v[pos][i] and !(mask >> i & 1)) {
            ans += solve(pos + 1, mask | (1 << i));
            ans %= MOD;
        }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)cin >> v[i][j];
    cout << solve(0, 0);
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