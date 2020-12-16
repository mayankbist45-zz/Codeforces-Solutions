#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int pre = 0, ed = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, mid, cur = i;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (v[mid] - v[i] <= k) {
                lo = mid + 1;
                cur = mid;
            } else {
                hi = mid - 1;
            }
        }
        ans += C(cur - i, m - 1);
        if(ans >= MOD)ans -= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(200000);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}