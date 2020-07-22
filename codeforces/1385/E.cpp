#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<bool> vis;
vector<int> g[maxn], o;

void dfs(int u) {
    vis[u] = true;
    for (auto x : g[u]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
    o.push_back(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)g[i].clear();
    o.clear();
    vis = vector<bool>(n + 1);

    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int a, b;
        cin >> a >> b;
        if (t)g[a].push_back(b);
        v.push_back({{a, b}, t});
    }
    for (int i = 1; i <= n; i++)if (!vis[i])dfs(i);
    reverse(o.begin(), o.end());
    map<int, int> mp;
    for (int i = 0; i < o.size(); i++) {
        mp[o[i]] = i;
        for (auto x: g[o[i]]) {
            if (mp.count(x)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto &y: v) {
        auto &x = y.first;
        if (y.second != 1 and mp[x.first] > mp[x.second])swap(x.first, x.second);
        cout << x.first << " " << x.second << endl;
    }
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