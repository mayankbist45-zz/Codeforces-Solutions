#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] = (v[i] + 1.0) / 2.0;
    }
    long double ans = 0, cur = 0;
    for (int i = 0; i < k; i++)cur += v[i];
    ans = max(ans, cur);
    for (int i = 0, j = k; j < n; i++, j++) {
        cur += v[j];
        cur -= v[i];
        ans = max(ans, cur);
    }
    cout << fixed << setprecision(10) << ans << endl;
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