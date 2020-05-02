#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

int pref[maxn][2], suf[maxn][2];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'E')pref[i + 1][0] = 1;
        else pref[i + 1][1] = 1;
        pref[i + 1][0] += pref[i][0];
        pref[i + 1][1] += pref[i][1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'E')suf[i + 1][0] = 1;
        else suf[i + 1][1] = 1;
        suf[i + 1][0] += suf[i + 2][0];
        suf[i + 1][1] += suf[i + 2][1];
    }

    int ans = 1e10;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, pref[i - 1][1] + suf[i + 1][0]);
    }
    cout << ans << endl;
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