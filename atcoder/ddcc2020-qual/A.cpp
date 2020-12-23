#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;

    int ans = 0;
    int price[] = {0, 300000, 200000, 100000};
    if (x <= 3)ans += price[x];
    if (y <= 3)ans += price[y];
    if (x == 1 and y == 1)ans += 400000;
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