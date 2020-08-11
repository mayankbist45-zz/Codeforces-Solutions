#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

string s;
int t, ptr = 1;
int dp[110][2601];

void solve() {
    cin >> s;

    int sum = 0;
    for (auto x: s)sum += x - 'a';
    int ans = 0;
    (ans += dp[s.size()][sum]) %= MOD;
    ans--;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[0][0] = 1;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 2600; j++)
            for (int k = 0; k < 26; k++) {
                if (j + k > 2600)continue;
                dp[i + 1][j + k] += dp[i][j];
                if (dp[i + 1][j + k] >= MOD) dp[i + 1][j + k] -= MOD;
            }
    cin >> t;

    for (; ptr <= t; ptr++)
        solve();
    return 0;
}