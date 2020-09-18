#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> a(n + 1);
    vector<long double> p(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] = p[i] / 100;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]++;
    }
    vector<vector<vector<long double>>> dp(210, vector<vector<long double>>(210, vector<long double>(210, 0.00)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int wins = 0; wins <= i; wins++) {
            for (int bags = 0; bags <= n; bags++) {
                dp[i + 1][wins + 1][min(n, bags + a[i])] += p[i] * dp[i][wins][bags];
                dp[i + 1][wins][bags] += (1 - p[i]) * dp[i][wins][bags];
            }
        }
    }
    long double ans = 0;
    for (int wins = 0; wins <= n; wins++) {
        for (int bags = 0; bags <= n; bags++) {
            if (wins >= l and wins <= bags + k)
                ans += dp[n][wins][bags];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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