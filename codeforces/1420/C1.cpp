#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

int dp[maxn][2];
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0][0] = v[0], dp[0][1] = -v[0];
    multiset<int> a, b;
    a.insert(v[0]);
    b.insert(-v[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(v[i], v[i] + *b.rbegin());
        dp[i][1] = max(-v[i], -v[i] + *a.rbegin());
        a.insert(dp[i][0]);
        b.insert(dp[i][1]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)mx = max({mx, dp[i][0], dp[i][1]});
    cout << mx << endl;
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