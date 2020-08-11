#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];

int pw(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int lmt = v.back(), ans = 0;
    for (int i = 1; i <= lmt; i++) {
        int cur = 1;
        for (int j = g[i].size() - 1; j >= 0; j--) {
            if (j + 1 == g[i].size()) {
                int val = n - (lower_bound(v.begin(), v.end(), i) - v.begin());
                (cur *= (pw(g[i].size(), val) - pw(g[i].size() - 1, val) + MOD) % MOD) % MOD;
            } else {
                int hi = lower_bound(v.begin(), v.end(), g[i][j + 1]) - v.begin();
                int lo = lower_bound(v.begin(), v.end(), g[i][j]) - v.begin();
                (cur *= pw(j + 1, hi - lo)) %= MOD;
            }
        }
        ans += cur;
        if (ans >= MOD)ans -= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            g[j].push_back(i);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}

