#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    multiset<int> pil;
    for (int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        pil.insert(tp);
    }

    int ans = 0;
    for (auto x: v) {
        if (pil.empty())break;
        auto tp = pil.lower_bound(x.first);
        if (tp != pil.end() and  (*tp) <= x.second) {
            ans++;
            pil.erase(tp);
        }
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
