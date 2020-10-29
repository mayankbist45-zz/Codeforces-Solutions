#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
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
    int n, x, pos;
    cin >> n >> x >> pos;

    int ct1 = 0, ct2 = 0;
    int lo = 0, hi = n, mid, fd = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (mid < pos) {
            ct1++;
            lo = mid + 1;
        } else if (mid > pos) {
            ct2++;
            hi = mid;
        } else if (mid == pos)fd = 1, lo = mid + 1;
    }
    int ans = C(x - 1, ct1) * C(n - x, ct2) % MOD;
    ans *= fact[n - ct1 - ct2 - 1] * fact[ct1] % MOD;
    ans %= MOD;
    ans *= fact[ct2] % MOD;
    ans %= MOD;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(2010);
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}