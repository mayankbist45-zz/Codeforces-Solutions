#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    sort(v.begin(), v.end());
    map<int, int> mp;
    int tp = v.back();
    for (int i = 0; i < n; i++) {
        if (mp.count(v[i]))continue;
        for (int j = 2 * v[i]; j <= 2 * tp; j += v[i]) {
            int zp = lower_bound(v.begin(), v.end(), j) - v.begin();
            ans = max(ans, v[zp - 1] % v[i]);
        }
        mp[v[i]] = 1;
    }
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