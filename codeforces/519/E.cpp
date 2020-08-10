#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
vector<vector<int>> up;
int tout[maxn], tin[maxn], dep[maxn], sz[maxn];
int timer = 0, L, n;

void dfs(int u, int p) {
    tin[u] = ++timer;
    sz[u] = 1;
    up[u][0] = p;
    for (int i = 1; i <= L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto &x: g[u]) {
        if (x == p)continue;
        dep[x] = 1 + dep[u];
        dfs(x, u);
        sz[u] += sz[x];
    }
    tout[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v))return u;
    if (isAncestor(u, v))return v;
    for (int i = L; i >= 0; i--)if (!isAncestor(up[u][i], v))u = up[u][i];
    return up[u][0];
}

void preprocess() {
    cin >> n;
    for (int a, b, i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1));
    dfs(1, 1);
}


void solve() {
    preprocess();
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << n << endl;
            continue;
        }

        int LCA = lca(a, b);
        int ans = 0;

        int d = dep[a] + dep[b] - 2 * dep[LCA];
        if (d & 1) {
            cout << 0 << endl;
            continue;
        }
        d /= 2;
        int cur = dep[a] - dep[LCA] >= d ? a : b;
        int ba = cur;

        d--;
        for (int i = L; i >= 0; i--) if ((d >> i) & 1)cur = up[cur][i];

        int ct = 0;

        if (up[cur][0] == LCA) {
            int othe = ba == a ? b : a;
            for (int i = L; i >= 0; i--) if ((d >> i) & 1)othe = up[othe][i];
            ans = n - sz[othe] - sz[cur];
        } else
            ans = sz[up[cur][0]] - sz[cur];
        cout << ans << endl;
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

//8
//1 2
//2 4 2 5
//1 3 3 6 3 7
//4 8

