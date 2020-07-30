#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int v[maxn], h[maxn], sz[maxn];
vector<int> g[maxn];
bool fl = true;

pair<int, int> dfs(int u, int p = -1) {
    sz[u] = v[u];
    pair<int, int> ret = {v[u], 0};
    for (auto x : g[u]) {
        if (x != p) {
            auto tp = dfs(x, u);
            v[u] += v[x];
            ret.first += tp.first;
            ret.second += tp.second;
        }
    }

    if ((h[u] + v[u]) & 1)fl = false;
    int hap = h[u] + v[u] >> 1;
    int sad = v[u] - hap;

    if (hap < 0 or sad < 0 or hap + sad != v[u])fl = false;

    if (hap < ret.first) {
        int d = ret.first - hap;
        if (d > sz[u])fl = false;
        else ret.first = hap, ret.second += d;
    }
    if (sad < ret.second) {
        int d = ret.second - sad;
        ret.second -= d, ret.first += d;
    }
    if (sad > ret.second) {
        int d = sad - ret.second;
        if (d > sz[u])fl = false;
        else ret.first -= d, ret.second += d;
    }
    if (hap > ret.first) fl = false;
    if (ret.first - ret.second != h[u])fl = false;
    return ret;
}

void solve() {
    fl = true;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)g[i].clear();
    for (int i = 0; i < n; ++i) cin >> v[i + 1];
    for (int i = 0; i < n; ++i) cin >> h[i + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    if (!fl)cout << "NO";
    else cout << "YES";
    cout << endl;
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