#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x;
    cin >> x;
    if (x == 0) {
        cout << 0 << endl;
        return;
    }
    int ans = LLONG_MAX;
    for (int i = 0; i < (1 << 9); i++) {
        vector<int> val;
        int sum = 0;
        for (int j = 0; j < 9; j++) {
            if ((i >> j) & 1) {
                val.push_back(j + 1);
                sum += (j + 1);
            }
        }
        if (sum == x) {
            sum = 0;
            for (auto x: val)sum = sum * 10 + x;
            ans = min(ans, sum);
        }
    }
    if (ans == LLONG_MAX)ans = -1;
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