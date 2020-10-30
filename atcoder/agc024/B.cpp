#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

/*
 * making the array sorted
 * lis on cons values maybe
 */

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> dp(n + 1);
    for (auto x: v)
        dp[x] = 1 + dp[x - 1];
    cout << n - *max_element(dp.begin(), dp.end()) << endl;
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