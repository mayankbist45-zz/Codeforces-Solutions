#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
using int32 = __uint32_t;

int pw(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}

int inverse(int a) {
    return pw(a, MOD - 2);
}

int nCr(int n, int r) {
    int num = 1;
    for (int i = n; i >= n - r + 1; i--) {
        num = (num * i) % MOD;
    }
    int inv = 1;
    for (int i = 1; i <= r; i++) {
        inv = (inv * i) % MOD;
    }
    return num * inverse(inv) % MOD;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = pw(2, n);
    ans = (ans - nCr(n, a) + MOD) % MOD;
    ans = (ans - nCr(n, b) + MOD) % MOD;

    ans = (ans + MOD - 1) % MOD;
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
