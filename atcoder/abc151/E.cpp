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
    preprocess(maxn - 1);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int maxS = 0;
    int prev = LLONG_MIN;
    int id = 0;
    for (int i = k - 1; i < n; i++) {
        maxS = (maxS + v[i] * C(i, k - 1) % MOD) % MOD;
    }
    sort(v.rbegin(), v.rend());
    int minS = 0;
    prev = LLONG_MAX, id = 0;
    for (int i = k - 1; i < n; i++) {
        minS = (minS + v[i] * C(i, k - 1) % MOD) % MOD;
    }
    int ans = (maxS - minS + MOD) % MOD;
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