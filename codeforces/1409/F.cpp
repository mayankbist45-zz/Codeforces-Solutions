#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

int n, k;
string a, b;

/*
 * dp[i][j][k] - no of seq by choosing i val from 1 string j no of b[0] and doing k steps
 */

int dp[maxn][maxn][maxn];

int solve(int p1, int p2, int step) {
    if (step > k)return INT_MIN;
    if (p1 == a.size())return 0;
    int &ans = dp[p1][p2][step];
    if (ans != -1)return ans;
    ans = 0;
    ans = max(ans, solve(p1 + 1, p2 + (a[p1] == b[0]), step) + (a[p1] == b[1] ? p2 : 0));
    //change to b0
    ans = max(ans, solve(p1 + 1, p2 + 1, step + 1) + (b[0] == b[1] ? p2 : 0));
    // change to b1
    ans = max(ans, solve(p1 + 1, p2 + (b[0] == b[1]), step + 1) + p2);
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> a >> b;
    cout << solve(0, 0, 0) << endl;
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