#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
char mat[maxn][maxn];
int h, w;
const int mod = 1e9 + 7;

void add_self(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

void go() {

    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            for (int r2 :{row, row + 1}) {
                int c2 = col;
                if (r2 == row)
                    c2 += 1;
                if (r2 < h && c2 < w && mat[r2][c2] == '.')
                    add_self(dp[r2][c2], dp[row][col]);
            }
        }
    }
    cout << dp[h - 1][w - 1];
}

int main() {
    cin >> h >> w;

    for (int u = 0; u < h; u++) {
        for (int j = 0; j < w; j++)
            cin >> mat[u][j];
    }

    go();
}