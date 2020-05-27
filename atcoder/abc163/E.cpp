#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

int dp[maxn][maxn];
pair<int, int> v[maxn];
int n;

int solve(int id, int l, int r) {
    if (id > n)return 0;
    int &ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = v[id].first * abs(v[id].second - l) + solve(id + 1, l + 1, r);
    ans = max(ans, v[id].first * abs(v[id].second - r) + solve(id + 1, l, r - 1));
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    reverse(v + 1, v + n + 1);
    cout << solve(1, 1, n) << endl;
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