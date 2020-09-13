#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

int dp[maxn];
void solve() {
    int s;
    cin >> s;

    dp[0] =1;
    for(int i = 0; i <= s; i++){
        for(int j = 3; j + i <= s; j++){
            dp[i + j] += dp[i];
            if(dp[i + j] >= MOD)dp[i + j] -= MOD;
        }
    }
    cout << dp[s] << endl;
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