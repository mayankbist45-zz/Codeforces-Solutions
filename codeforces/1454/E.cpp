#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> cycle;
int vis[maxn], par[maxn];
vector<int> g[maxn];

bool dfs(int u, int p = -1) {
    vis[u] = 1;
    par[u] = p;
    for (auto x : g[u]) {
        if (!vis[x]) {
            bool val = dfs(x, u);
            if (val)return val;
        } else if (vis[x] == 1 and p != x) {
            //cycle found
            int cur = u;
            while (cur != x) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(x);
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

int solve(int u) {
    vis[u] = true;
    int ret = 1;
    for (auto x : g[u]) {
        if (!vis[x] and !binary_search(cycle.begin(), cycle.end(), x)) {
            ret += solve(x);
        }
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;

    cycle.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    sort(cycle.begin(), cycle.end());
    int ans = 0;

    for (int i = 0; i <= n; i++) vis[i] = false;

    for (auto x: cycle) {
        int val = solve(x);
        ans += val * (val - 1);
        ans += 2 * (n - val) * val;
    }
    cout << ans / 2 << endl;
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