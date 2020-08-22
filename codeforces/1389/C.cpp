#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int ans = LLONG_MAX;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++) {
            int cur = 0, ct = 0;
            for (int id = 0; id < s.size(); id++) {
                if (cur) {
                    if (s[id] == j + '0') {
                        cur ^= 1;
                        ct++;
                    }
                } else {
                    if (s[id] == i + '0') {
                        cur ^= 1;
                        ct++;
                    }
                }
            }
            if (ct & 1 and i != j)ct--;
            ans = min(ans, (int) s.size() - ct);
        }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}