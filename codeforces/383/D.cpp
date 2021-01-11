#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 10010
const int MOD = 1000000007;

int n;
vector<int> v;
int dp[1010][2 * maxn][2];
int solve(int pos, int sum, int start) {
    if (pos == n) {
        return sum == 0 and start;
    }
    int &ans = dp[pos][sum + 10000][start];
    if (ans != -1)return ans;
    ans = (start ? (sum == 0) : 0);
    if (!start)ans += solve(pos + 1, 0, start) % MOD;
    (ans += solve(pos + 1, sum + v[pos], 1)) %= MOD;
    (ans += solve(pos + 1, sum - v[pos], 1)) %= MOD;
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << solve(0, 0, 0) << endl;
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