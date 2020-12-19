#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010

int v[maxn];
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> v[i];

    int cur = 0;
    for (int i = n; i > 1; i--) {
        v[i] -= v[i - 1];
        cur = __gcd(cur, v[i]);
    }
//    cout << __gcd((int)2e18, 0ll);
    for (int i = 1, tp; i <= m; ++i) {
        cin >> tp;
        v[1] += tp;
        cout << abs(__gcd(cur, v[1])) << " ";
        v[1] -= tp;
    }
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