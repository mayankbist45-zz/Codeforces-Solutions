#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 50
const int MOD = 1000000007;
vector<vector<int>> v;
int dp[maxn][3][3][3];
int solve(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
//        cout << "Move disk 1 from rod " << from_rod <<
//             " to rod " << to_rod << " with " << v[from_rod][to_rod] << endl;
        return min(v[from_rod][to_rod], v[from_rod][aux_rod] + v[aux_rod][to_rod]);
    }
    if (dp[n][from_rod][to_rod][aux_rod] != -1)return dp[n][from_rod][to_rod][aux_rod];
    int ans = solve(n - 1, from_rod, aux_rod, to_rod) + v[from_rod][to_rod] + solve(n - 1, aux_rod, to_rod, from_rod);
    ans = min(ans, solve(n - 1, from_rod, to_rod, aux_rod) + v[from_rod][aux_rod] +
                   solve(n - 1, to_rod, from_rod, aux_rod) + v[aux_rod][to_rod] +
                   solve(n - 1, from_rod, to_rod, aux_rod));
    return dp[n][from_rod][to_rod][aux_rod] = ans;
//    cout << "Move disk " << n << " from rod " << from_rod <<
//         " to rod " << to_rod << " with " << v[from_rod][to_rod] << endl;;
}

void solve() {
    v = vector<vector<int>>(3, vector<int>(3, 0));
    for (auto &x: v)
        for (auto &y: x) {
            cin >> y;
        }
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << solve(n, 0, 2, 1);
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