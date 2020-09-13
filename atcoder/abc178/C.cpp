#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

int pw(int a, int b, int m = MOD) {
    if (b == 0)return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}

int inverse(int a) {
    return pw(a, MOD - 2);
}

int fact[maxn], inv[maxn];

void preprocess(int lmt) {
    fact[0] = 1;
    for (int i = 1; i <= lmt; i++)fact[i] = (fact[i - 1] * i) % MOD;
    inv[lmt] = inverse(fact[lmt]);
    for (int i = lmt - 1; i >= 0; i--)inv[i] = (i + 1) * inv[i + 1] % MOD;
}


int C(int n, int r) {
    if (r > n)return 0;
    return fact[n] * inverse(fact[r] * fact[n - r] % MOD) % MOD;
}

void solve() {
    int n;
    cin >> n;

    int ans = pw(10, n) - pw(8, n);
    ans += MOD;
    ans %= MOD;
    for (int i = 1; i <= n; i++) {
        int val = 2 * pw(8, n - i) % MOD;
        (val *= C(n, i)) %=MOD;
        ans = ans - val;
        ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(1000000);
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}