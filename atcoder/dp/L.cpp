#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 3010
const int MOD = 1000000007;

int v[maxn];
int dp[maxn][maxn];

int solve(int l, int r) {
    if (l > r)return 0;
    int &ans = dp[l][r];
    if (ans != -1)return ans;
    ans = v[l] - solve(l + 1, r);
    ans = max(ans, v[r] - solve(l, r - 1));
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
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

