#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int ct = 0;
        for (int j = 30; j >= 0; j--) {
            if ((v[i] >> j) & 1) {
                mp[j]++;
                break;
            }
        }
    }
    int ans = 0;
    for (auto x: mp)ans += x.second * (x.second - 1) / 2;
    cout << ans << endl;;
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