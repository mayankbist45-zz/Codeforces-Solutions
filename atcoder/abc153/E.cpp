#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int MOD = 1000000007;
const int INF = 1e14;

void solve() {
    int h, n;
    cin >> h >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v.emplace_back(a, b);
    }
    vector<int> dp(h + 1, INF);
    dp[h] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = h; j >= 0; j--) {
            dp[max(j - v[i].first, 0ll)] = min(dp[max(j - v[i].first, 0ll)], dp[j] + v[i].second);
        }
    }
    cout << dp[0] << endl;
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