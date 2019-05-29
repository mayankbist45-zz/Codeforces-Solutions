#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int32_t main() {
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> mat[i][j];
        }
    }
    int dp[h][w] = {};
    for (int k = 0; k < h; ++k) {
        if (mat[k][0] == '#')
            break;
        dp[k][0] = 1;
    }
    for (int k = 0; k < w; ++k) {
        if (mat[0][k] == '#')
            break;
        dp[0][k] = 1;
    }
    for (int i = 1; i < h; i++)
        for (int j = 1; j < w; j++) {
            if (mat[i][j] == '#')
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j]%MOD + dp[i][j - 1]%MOD;
        }

    cout << dp[h - 1][w - 1]%MOD;
}

