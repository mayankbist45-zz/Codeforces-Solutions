#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n;
int solve(int l, int r, int h, vector<int> &v) {
    if (l == r)return 1;
    int mn = LLONG_MAX;
    for (int i = l; i <= r; i++)mn = min(mn, v[i]);
    int ans = mn - h, lf = l;
    for (int i = l; i <= r; i++) {
        if (v[i] == mn) {
            if (i != lf)ans += solve(lf, i - 1, mn, v);
            lf = i + 1;
        }
    }
    if(v[r] != mn)ans += solve(lf, r, mn, v);
    return min(ans, r - l + 1);
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << solve(0, n - 1, 0, v);
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