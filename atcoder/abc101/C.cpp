#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n), dp(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i - k + 1 >= 0)
            dp[i] = 1 + dp[i - k + 1];
    }
    int mx = dp[n - 1];
    for (int i = n - 2; i >= 0; i--)
        if (mx == dp[i]) {
            mx++;
            break;
        }
    cout << mx << endl;
}