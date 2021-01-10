#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 5010
const int MOD = 1000000007;

int dp[maxn][maxn];

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)dp[i][i] = 1;
    for (int gap = 1; gap < s.size(); gap++) {
        for (int i = 0; i < s.size() and i + gap < s.size(); i++) {
            int j = i + gap;
            if (s[i] == s[j]) {
                if (i + 1 <= j - 1)
                    dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1;
            }
        }
    }
    for (int gap = 1; gap < s.size(); gap++) {
        for (int i = 0; i < s.size() and i + gap < s.size(); i++) {
            int j = i + gap;
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }

    int q;
    cin >> q;
    for (int a, b, i = 0; i < q; i++) {
        cin >> a >> b;
        cout << dp[a - 1][b - 1] << endl;
    }
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