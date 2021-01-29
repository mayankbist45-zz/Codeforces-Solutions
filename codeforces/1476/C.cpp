#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];


    vector<int> dp(n);
    dp[1] = abs(a[1] - b[1]) + 2 + v[1] - 1;
    for (int i = 2; i < n; i++) {
        dp[i] = (a[i] == b[i] ? 1 + v[i] : dp[i - 1] - abs(a[i] - b[i]) + 2 + v[i] - 1);
        dp[i] = max(dp[i], 2 + v[i] - 1 + abs(a[i] - b[i]));
    }
    int ans = 0;
    for (int i = 1; i < n; i++)ans = max(ans, dp[i]);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}