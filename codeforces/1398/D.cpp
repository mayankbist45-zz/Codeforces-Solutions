#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

vector<int> R, G, B;
int dp[maxn][maxn][maxn];
int r, g, b;

int solve(int i, int j, int k) {
    int &ans = dp[i][j][k];
    if (ans != -1)return ans;
    ans = 0;
    if (i < r)ans = max(ans, solve(i + 1, j, k));
    if (j < g)ans = max(ans, solve(i, j + 1, k));
    if (k < b)ans = max(ans, solve(i, j, k + 1));

    if (i < r and j < g)ans = max(ans, R[i] * G[j] + solve(i + 1, j + 1, k));
    if (i < r and k < b)ans = max(ans, R[i] * B[k] + solve(i + 1, j, k + 1));
    if (j < g and k < b)ans = max(ans, G[j] * B[k] + solve(i, j + 1, k + 1));
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> r >> g >> b;

    R = vector<int>(r);
    G = vector<int>(g);
    B = vector<int>(b);
    for (int i = 0; i < r; i++)cin >> R[i];
    for (int i = 0; i < g; i++)cin >> G[i];
    for (int i = 0; i < b; i++)cin >> B[i];

    sort(R.rbegin(), R.rend());
    sort(G.rbegin(), G.rend());
    sort(B.rbegin(), B.rend());

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