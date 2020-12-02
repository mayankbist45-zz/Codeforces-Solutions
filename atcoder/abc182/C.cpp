#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    bool fd = false;
    int mn = LLONG_MAX;
    for (int i = 1; i < (1 << s.size()); i++) {
        int cur = 0;
        for (int j = 0; j < s.size(); j++) {
            if (i >> j & 1)cur += s[j] - '0';
        }
        if (cur % 3 == 0) {
            fd = true;
            mn = min(mn, (int) s.size() - (int) __builtin_popcountll(i));
        }
    }
    if (!fd)cout << -1;
    else cout << mn;
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