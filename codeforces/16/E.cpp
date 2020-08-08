#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 20
const int MOD = 1000000007;

double a[maxn][maxn];
int n;
double dp[(1 << 18) + 1];

double solve(int mask) {
    if (__builtin_popcount(mask) == n)return 1;
    double &ans = dp[mask];

    if (ans >= 0)return ans;
    ans = 0;

    int rem = 1 + __builtin_popcount(mask);
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
            for (int j = 0; j < n; j++) {
                if (i == j)continue;
                if (mask >> j & 1)continue;
                double deno = rem * (rem + 1) / 2 - rem;
                ans += solve(mask | (1 << j)) * a[i][j] / (double) (deno);
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n;

    fill(dp, dp + (1 << 18) + 1, -1);
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> a[i][j];

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        double ans = solve(1 << i);
        cout << ans << " ";
    }
    cout << endl;
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

//4
//0 0.5 0.5 0.5
//0.5 0 0.5 0.5
//0.5 0.5 0 0.5
//0.5 0.5 0.5 0