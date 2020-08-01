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
    int h, w, n;
    cin >> h >> w >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({h, w});
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    vector<int> dp(v.size());
    for (int i = 0; i < v.size(); i++) {
        dp[i] = C(v[i].first + v[i].second - 2, v[i].first - 1);
        for (int j = 0; j < i; j++) {
            if (v[j].second <= v[i].second) {
                int val = C(v[i].first - v[j].first + v[i].second - v[j].second, v[i].first - v[j].first);
                dp[i] = (dp[i] - dp[j] * val % MOD + MOD) % MOD;
            }
        }
    }
    cout << dp.back() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess(200000);
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}