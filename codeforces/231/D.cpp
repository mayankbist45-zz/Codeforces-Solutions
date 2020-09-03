#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int a[10];

void solve() {
    int x, y, z;
    cin >> x >> y >> z;

    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;

    int ans = 0;
    for (int i = 1; i <= 6; i++)cin >> a[i];
    if (x > x1)ans += a[6];
    if (y > y1)ans += a[2];
    if (z > z1)ans += a[4];
    if (x < 0)ans += a[5];
    if (y < 0)ans += a[1];
    if (z < 0)ans += a[3];
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