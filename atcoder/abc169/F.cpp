#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 998244353;

/*
 * count no of ways to make sum of values
 * equal to S out of the diffrent subsets of
 * different of subsets of {1,2,3,...,n}
 *
 * Note :- We pick a subset of numbers from a
 * set now we want to find no of subsets in which
 * this set lies. This is equal to 2^(n - k) where k
 * is the size of our picked subset and n is the orig
 * set. Since for each n - k elements we can either
 * pick it or not pick it
 *
 * dp[i + 1][j] += dp[i][j];
 * dp[i + 1][j + a[i]] = dp[i][j]/2;
 *
 * ans is dp[n][s]
 */

int pw(int a, int b) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % MOD;
    return pw(a * a % MOD, b / 2);
}

int inverse(int a) {
    return pw(a, MOD - 2);
}

void solve() {
    int n, s;
    cin >> n >> s;

    int inv = inverse(2);
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    auto add = [](int &a, int b) {
        a += b;
        if (a >= MOD)a -= MOD;
    };
    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp[0][0] = pw(2, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            add(dp[i + 1][j], dp[i][j]);
            if (j + v[i] <= s)
                add(dp[i + 1][j + v[i]], dp[i][j] * inv % MOD);
        }
    }
    cout << dp[n][s] << endl;
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