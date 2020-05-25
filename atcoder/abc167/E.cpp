#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 998244353;

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
    preprocess(maxn - 1);
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int cur = m * pw(m - 1, n - 1 - i);
        cur %= MOD;
        cur *= C(n - 1, i);
        cur %= MOD;
        ans += cur;
        ans %= MOD;
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