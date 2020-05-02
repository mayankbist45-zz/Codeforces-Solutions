#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    ans += min(n, m / 2);
    int tp = m;
    m -= min(2 * n, m - m % 2);
    n -= min(n, tp / 2);
    if (n == 0) {
        ans += m / 4;
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