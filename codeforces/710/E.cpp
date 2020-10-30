#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> dp(n + 1);
    dp[1] = x;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + x;
        dp[i] = min(dp[i], dp[(i + 1) / 2] + y + (i & 1 ? x : 0));
    }
    cout << dp[n] << endl;
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