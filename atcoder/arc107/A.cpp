#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 998244353;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int su1 = a * (a + 1) / 2;
    int su2 = b * (b + 1) / 2;
    int su3 = c * (c + 1) / 2;

    su1 %= MOD;
    su2 %= MOD;
    su3 %= MOD;
    int ans = su1 * su2 % MOD;
    cout << ans * su3 % MOD << endl;
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

