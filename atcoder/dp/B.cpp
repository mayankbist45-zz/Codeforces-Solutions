#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {

    int n , k;
    cin >> n >> k;

    vector<int> h(n + 1, 0), dp(n, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++) {
        for (int j = i ; j <= i+k ;j++) {
            if (j < n)
                dp[j] = min(dp[j], abs(h[i] - h[j]) + dp[i]);
        }
    }
    cout << dp[n - 1];
}



