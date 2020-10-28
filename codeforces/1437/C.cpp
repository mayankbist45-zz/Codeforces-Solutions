#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n;
vector<int> v;
vector<vector<int>> dp;
int solve(int pos, int val) {
    if (pos == n)return 0;
    if (val > 400)return INT_MAX;

    int &ans = dp[pos][val];
    if (ans != -1)return ans;
    ans = solve(pos, val + 1);
    ans = min(ans, abs(v[pos] - val) + solve(pos + 1, val + 1));
    return ans;
}

void solve() {
    cin >> n;
    dp = vector<vector<int>>(n + 1, vector<int>(410, -1));
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << solve(0, 1) << endl;
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