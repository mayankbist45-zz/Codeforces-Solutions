#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, vector<int>> mp;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mp[b].push_back(a);
    }
    vector<pair<int, int>> v;
    for (auto x: mp) {
        if (x.second.size() == 2)v.push_back({x.first, 2});
        else if (x.second.front() == 1)v.push_back({x.first, -1});
        else v.push_back({x.first, 1});
    }

    bool fd = true;
    for (int i = 0; i < v.size() and fd; i++) {
        if (v[i].second == 2)continue;
        if (i + 1 < v.size()) {
            if (v[i + 1].second == 2) {
                fd = false;
                break;
            }
            int dist = v[i + 1].first - v[i].first + 1;
            if (v[i + 1].second != v[i].second) {
                if (dist % 2 == 0)fd = false;
            } else if (dist & 1)fd = false;
        } else fd = false;
        i++;
    }
    if (!fd) cout << "NO" << endl;
    else cout << "YES" << endl;
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