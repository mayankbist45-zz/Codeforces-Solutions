#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ct1 = b / c - (a - 1) / c;
    int ct2 = b / d - (a - 1) / d;
    int lcm = c / __gcd(c, d) * d;
    cout << (b - a + 1) - (ct1 + ct2 - (b/lcm - (a - 1)/lcm));
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