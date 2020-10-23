#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

/*
 * binary search would do
 */

void solve() {
    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;

    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> mp;
    for (auto &x: s)mp[x]++;
    auto check = [&](int val) -> bool {
        int times = val / n;
        int u = times * mp['U'];
        int d = times * mp['D'];
        int l = times * mp['L'];
        int r = times * mp['R'];

        map<int, int> tp;
        for (int i = 0; i < val % n; i++) {
            tp[s[i]]++;
        }
        u += tp['U'];
        d += tp['D'];
        l += tp['L'];
        r += tp['R'];
        int x = x1 + r - l, y = y1 + u - d;
        int dist = abs(x - x2) + abs(y - y2);
        return dist <= val;
    };

    int lo = 0, hi = 1e16, mid, ans = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ans = mid;
        } else lo = mid + 1;
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