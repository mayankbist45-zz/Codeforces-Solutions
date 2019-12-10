#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for (int i = 0; i < n - 1; i++) {
        if (dp[i] > v[i]) {
            dp[i] = v[i];
            dp[i + 1] = v[i];
        } else
            dp[i + 1] = v[i];
    }
    int ans = 0;
    for (auto x:dp)
        ans += x;
    cout << ans << endl;
    return 0;
}