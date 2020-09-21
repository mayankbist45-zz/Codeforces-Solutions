#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
int sz[maxn], par[maxn], n, mx = INT_MAX;
vector<int> g[maxn];
vector<int> ct, lff;
 
void dfs(int u, int p = -1) {
    sz[u] = 1;
    int cur = 0;
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs(x, u);
        cur = max(cur, sz[x]);
        sz[u] += sz[x];
    }
    cur = max(cur, n - sz[u]);
    if (cur == mx)ct.push_back(u);
    else if (cur < mx) {
        ct.clear();
        ct.push_back(u);
        mx = cur;
    }
}
 
void getleaf(int u, int p = -1) {
    par[u] = p;
    bool lf = true;
    for (auto x : g[u]) {
        if (x == p)continue;
        lf = false;
        getleaf(x, u);
    }
    if (lf)lff.push_back(u);
}
 
void solve() {
    cin >> n;
 
    mx = INT_MAX;
    ct.clear();
    lff.clear();
    for (int i = 0; i <= n; i++)g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    if (ct.size() == 1) {
        cout << g[1].front() << " " << 1 << endl;
        cout << g[1].front() << " " << 1 << endl;
    } else {
        int node = -1;
        for (auto tp : ct) {
            for (auto x: g[tp]) {
                if (sz[x] == mx) {
                    node = x;
                    for (auto x: g[tp]) {
                        if (x == node)continue;
                        else {
                            getleaf(x, tp);
                            int zp = lff.front();
                            cout << zp << " " << par[zp] << endl;
                            cout << zp << " " << node << endl;
                            return;
                        }
                    }
                    break;
                }
            }
 
        }
 
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