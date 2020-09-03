#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int sz[maxn], n;
vector<int> g[maxn];

int in[maxn], out[maxn], ans = 0;

void dfs1(int u, int p = -1) {
    sz[u] = 1;
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs1(x, u);
        sz[u] += sz[x];
        in[u] += in[x];
    }
    in[u] += sz[u];
}

void dfs2(int u, int p = -1) {
    ans = max(ans, out[u] + in[u] + n - sz[u]);
    for (auto x :g[u]) {
        if (x == p)continue;
        out[x] = out[u] + in[u] - in[x] - sz[x] + (n - sz[u]);
        dfs2(x, u);
    }
}

void solve() {
    cin >> n;

    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1);
    dfs2(1);
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