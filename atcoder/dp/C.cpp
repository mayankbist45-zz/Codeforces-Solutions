#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;

int solve(int dp[100010][3]) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            int ans = -1e14;
            for (int k = 0; k < 3; k++) {
                if (j != k)
                    ans = max(dp[i + 1][k], ans);
            }
            dp[i][j] += ans;
        }
    }
    int ans = -1e14;
    for (int l = 0; l < 3; ++l) {
        ans = max(ans, dp[0][l]);
    }
    return ans;
}


int32_t main() {

    int dp[100010][3];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
        }
    }
    cout << solve(dp) << endl;

}

