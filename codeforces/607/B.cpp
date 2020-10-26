#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> v;
vector<vector<int>> dp;
int solve(int l, int r) {
    if (l == r)return 1;
    if (l > r)return 0;

    int &ans = dp[l][r];
    if (ans != -1)return ans;
    ans = 1 + solve(l + 1, r);
    if (l + 1 <= r and v[l] == v[l + 1])
        ans = min(ans, 1 + solve(l + 2, r));
    for (int i = l + 2; i <= r; i++) {
        if (v[i] == v[l])
            ans = min(ans, solve(l + 1, i - 1) + solve(i + 1, r));
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    cout << solve(0, n - 1) << endl;
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