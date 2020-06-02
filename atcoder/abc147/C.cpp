#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> p[n + 1];

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;

            p[i].push_back({a, b});
        }
    }

    int64_t ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        //1 means honest
        bool fl = true;
        for (int i = 1; i <= n; i++) {
            bool isHonest = bit & (1 << (i - 1));
            if (isHonest) {
                for (auto x: p[i]) {
                    int val = x.second;
                    int id = x.first - 1;
                    bool hon = bit & (1 << id);
                    if (hon != x.second)fl = false;
                }
            }
        }
        if (fl)ans = max(ans, (int64_t) __builtin_popcount(bit));
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
