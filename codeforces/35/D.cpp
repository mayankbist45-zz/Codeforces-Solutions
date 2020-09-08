#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int c[maxn], n, x, dp[101][10010];

int solve(int pos, int val) {
    if (pos == n)return 0;
    int &ans = dp[pos][val];
    if (ans != -1)return ans;
    ans = solve(pos + 1, val);
    if (val + c[pos] <= x)
        ans = max(ans, 1 + solve(pos + 1, val + c[pos]));
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] = (n - i) * c[i];
    }
    cout << solve(0, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO();
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}