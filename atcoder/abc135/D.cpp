#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

string s;
int dp[maxn][13];
int solve(int pos, int mod) {
    if (pos == s.size()) {
        return mod == 5;
    }
    int &ans = dp[pos][mod];
    if (ans != -1)return ans;
    ans = 0;
    if (s[pos] == '?') {
        for (int i = 0; i <= 9; i++){
            ans += solve(pos + 1, (mod * 10 % 13 + i) % 13);
            if(ans >= MOD)ans -= MOD;
        }
    } else ans += solve(pos + 1, (mod * 10 % 13 + s[pos] - '0') % 13);
    if(ans >= MOD)ans -= MOD;
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << solve(0, 0);
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