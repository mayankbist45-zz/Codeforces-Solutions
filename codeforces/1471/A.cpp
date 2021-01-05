#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx += v[i] / x + (v[i] % x > 0);
    }
    int sum = accumulate(v.begin(), v.end(), 0ll);
    int mn = sum / x + (sum % x > 0);

    cout << mn << " " << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}