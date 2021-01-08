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
    int d;
    cin >> d;

    vector<int> prime;
    for (int i = 2; i * i <= d; i++) {
        int cnt = 0;
        while (d % i == 0)d /= i, cnt++;
        if (cnt)prime.push_back(i);
    }
    if (d > 1)prime.push_back(d);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        int gcd = __gcd(a, b);
        // a -> gcd then gcd -> b
        vector<int> one, two;
        for (auto x: prime) {
            int cnt = 0;
            while (a % x == 0)cnt++, a /= x;
            while (b % x == 0)cnt--, b /= x;
            if (cnt < 0)two.push_back(-cnt);
            else if (cnt > 0)one.push_back(cnt);
        }
        int ans = fact[accumulate(one.begin(), one.end(), 0ll)];
        for (auto x: one)(ans *= inv[x]) %= MOD;
        (ans *= fact[accumulate(two.begin(), two.end(), 0ll)]) %= MOD;
        for (auto x: two)(ans *= inv[x]) %= MOD;
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(51);
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}