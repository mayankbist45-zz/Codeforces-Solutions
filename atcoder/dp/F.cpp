#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {

    string s, t;
    cin >> s >> t;

    int a = s.size(), b = t.size();
    int dp[a + 1][b + 1] = {};

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = a, j = b;
    while (i > 0 and j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin() ,ans.end());

    cout << ans << endl;
}

