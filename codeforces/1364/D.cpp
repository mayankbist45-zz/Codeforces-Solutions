#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int visited[maxn], par[maxn], dep[maxn];
vector<int> white, black;
vector<int> cycle;

bool dfs(int u, int color) {
    visited[u] = 1;
    if (color == 0)white.push_back(u);
    else black.push_back(u);

    int val = -1, id = -1;
    for (auto x: g[u]) {
        if (visited[x] == 1 and x != par[u] and dep[x] > val) {
            val = dep[x];
            id = x;
        }
    }
    if (id != -1) {
        int cur = u;
        while (cur != id) {
            cycle.push_back(cur);
            cur = par[cur];
        }
        cycle.push_back(id);
        return true;
    }

    for (auto x : g[u]) {
        if (!visited[x]) {
            dep[x] = 1 + dep[u];
            par[x] = u;
            if (dfs(x, color ^ 1))return true;
        }
    }
    visited[u] = 2;
    return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (dfs(1, 0)) {
        if (cycle.size() <= k) {
            cout << 2 << endl;
            cout << cycle.size() << endl;
            for (auto x: cycle)cout << x << " ";
        } else {
            cout << 1 << endl;
            int id = 0;
            for (int i = 0; i < (k + 1) / 2; i++)cout << cycle[id] << " ", id += 2;
        }
    } else {
        if (white.size() < black.size())swap(white, black);
        cout << 1 << endl;
        for (int i = 0; i < (k + 1) / 2; i++)cout << white[i] << " ";
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