#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int val[maxn], par[maxn], n;
vector<int> g[maxn];

void dfs(int u, int p = -1) {
    par[u] = p;
    for (auto x : g[u]) {
        if (x == p)continue;
        val[x] += val[u];
        dfs(x, u);
    }
}

void solve() {
    cin >> n;
    vector<pair<int, int>> v(n - 1);
    for (auto &x: v) {
        cin >> x.first >> x.second;
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }

    auto solve = [&](int a, int b, int x) {
        if (par[a] == b) val[a] += x;
        else val[1] += x, val[b] -= x;
    };
    dfs(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, e, x;
        cin >> t >> e >> x;
        e--;
        if (t == 1) solve(v[e].first, v[e].second, x);
        else solve(v[e].second, v[e].first, x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << val[i] << endl;
    }
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