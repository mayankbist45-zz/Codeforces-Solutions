#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;


int n, m, v[maxn], b[maxn], dp[maxn][maxn];

int solve(int pos1, int pos2) {
    if (pos1 == n or pos2 == m) {
        return n - pos1 + m - pos2;
    }
    int &ans = dp[pos1][pos2];
    if (ans != -1)return ans;
    ans = INT_MAX;

    ans = min(ans, (v[pos1] != b[pos2]) + solve(pos1 + 1, pos2 + 1));
    ans = min(ans, 1 + solve(pos1 + 1, pos2));
    ans = min(ans, 1 + solve(pos1, pos2 + 1));
    
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    cout << solve(0, 0) << endl;
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