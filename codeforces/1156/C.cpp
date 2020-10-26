#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, z;
    cin >> n >> z;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0, j = n / 2; i < n / 2 and j < n; i++) {
        while (j < n and v[i] - v[j] < z)j++;
        if (j < n)ans++;
        j++;
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