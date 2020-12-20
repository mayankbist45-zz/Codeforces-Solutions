#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(m);

    set<pair<int, int>> col[n + 1];
    vector<bool> vis(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        col[v[i].second].insert({v[i].first, i});
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (vis[i])continue;
        auto x = v[i];
        vis[i] = 1;
        if (x.second == x.first) {
            continue;
        }
        int cur = x.first;
        int ct = 1;
        while (!col[cur].empty()) {
            ct++;
            auto tp = *col[cur].begin();
            col[cur].erase(col[cur].begin());
            cur = tp.first;
            vis[tp.second] = 1;
            if (cur == x.second) {
                ans++;
                break;
            }
        }
        col[x.second].erase({x.first, i});
        ans += ct;
    }
    cout << ans << endl;
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