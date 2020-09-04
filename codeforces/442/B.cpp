#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<long double> v(n + 1);
    v[0] = LDBL_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> v[i + 1];
    }
    sort(v.rbegin(), v.rend());
    long double mx = 0;
    for (int i = 1; i <= n; i++) {
        long double sum = 0;
        for (int j = 1; j <= i; j++) {
            long double an = 1;
            for (int k = 1; k <= i; k++) {
                if (k == j) {
                    an *= v[k];
                    continue;
                }
                an *= (1 - v[k]);
            }
            sum += an;
        }
        mx = max(mx, sum);
    }
    cout << fixed << setprecision(10) << mx << endl;
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