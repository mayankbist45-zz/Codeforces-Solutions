#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 110
const int MOD = 1000000007;

char mat[maxn][maxn];

int h, w;

bool valid(int a, int b) {
    return a >= 1 and a <= h and b >= 1 and b <= w;
}

int dp[210][210][2];

int solve(int i, int j, bool subs = false) {
    if (i == h and j == w) {
        return 0;
    }

    int &ans = dp[i][j][subs];
    if (ans != -1)
        return ans;
    ans = 1e10;
    int x = i + 1, y = j;
    if (valid(x, y)) {
        if (mat[x][y] == '#') {
            if (subs)
                ans = min(ans, solve(x, y, subs));
            else
                ans = min(ans, 1 + solve(x, y, true));
        } else {
            ans = min(ans, solve(x, y, false));
        }
    }
    x = i, y = j + 1;
    if (valid(x, y)) {
        if (mat[x][y] == '#') {
            if (subs)
                ans = min(ans, solve(x, y, subs));
            else
                ans = min(ans, 1 + solve(x, y, true));
        } else {
            ans = min(ans, solve(x, y, false));
        }
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> h >> w;

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> mat[i][j];

    bool fl = false;
    if (mat[1][1] == '#')
        fl = true;
    cout << solve(1, 1, fl) + fl << endl;
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