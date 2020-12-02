#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int dp[10][10];
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> city(n - 1);
    iota(city.begin(), city.end(), 1ll);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dp[i][j];
    int ans = 0;
    do {
        int cur = 0, prev = 0;
        for(auto x: city){
            cur += dp[prev][x];
            prev = x;
        }
        cur += dp[prev][0];
        ans += cur == k;
    } while (next_permutation(city.begin(), city.end()));
    cout << ans << endl;
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