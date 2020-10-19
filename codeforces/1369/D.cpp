#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2000010
const int MOD = 1000000007;

vector<int> dp(maxn);
void process() {
    dp[3] = dp[4] = 1;
    for (int i = 5; i < maxn; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2 % MOD + (i % 3 == 0);
        dp[i] %= MOD;
    }
    for (int i = 3; i < maxn; i++)(dp[i] *= 4) %= MOD;
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    process();
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}