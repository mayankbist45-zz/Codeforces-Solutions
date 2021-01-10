#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int n, k, m;
int pw[maxn], pw9[maxn];
int dp[maxn][maxn];

int solve(int pos, int val, int cap = 0) {
    if (val == 0 and cap)
        return (pos == n) ? 1ll : 9ll * pw9[n - pos - 1] % m;
    if (pos == n)return 0;
    int &ans = dp[pos][val];
    if (ans != -1)return ans;
    ans = 0;
    for (int d = 0; d <= 9; d++) {
        (ans += solve(pos + 1, (d * pw[pos] % k + val) % k, cap | (d != 0))) %= m;
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> m;
    pw[0] = pw9[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 10 % k;
        pw9[i] = pw9[i - 1] * 10 % m;
    }
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