#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;

    vector<int> c(10);
    for (int i = 0; i < 6; i++)cin >> c[i + 1];

    for (int i = 0; i <= 60; i++) {
        c[1] = min(c[1], c[2] + c[6]);
        c[2] = min(c[2], c[1] + c[3]);
        c[3] = min(c[3], c[2] + c[4]);
        c[4] = min(c[4], c[3] + c[5]);
        c[5] = min(c[5], c[4] + c[6]);
        c[6] = min(c[6], c[5] + c[1]);
    }
    int ans = 0;
    if (x >= 0) {
        if (y >= 0) {
            ans += c[1] * min(x, y);
            int val = min(x, y);
            x -= val, y -= val;
            ans += c[6] * x;
            ans += c[2] * y;
        } else ans = abs(y) * c[5] + c[6] * x;
    } else {
        if (y >= 0) {
            ans = c[3] * abs(x) + c[2] * y;
        } else {
            ans = c[4] * min(abs(x), abs(y));
            int val = min(-1 * x, y * -1);
            x += val, y += val;
            ans += c[3] * abs(x);
            ans += c[5] * abs(y);
        }
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