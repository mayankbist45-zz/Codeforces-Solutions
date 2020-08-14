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
        mp[v[i]]++;
    }
    vector<pair<int, int>> vp;
    for (auto x: mp)vp.push_back({x.second, x.first});
    sort(vp.rbegin(), vp.rend());
    int ans = 0, cur = LLONG_MAX;
    for (auto &x: vp) {
        if (x.first < cur) {
            cur = x.first;
            ans += x.first;
        } else {
            x.first = cur - 1;
            cur--;
            ans += x.first;
        }
        if (cur - 1 == 0)break;
    }
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