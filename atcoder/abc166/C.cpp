#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int visited[maxn], h[maxn];
vector<int> g[maxn];
int ct;

void dfs(int u) {
    visited[u] = true;
    bool ch = true;
    for (auto x: g[u]) {
        if (h[x] >= h[u])
            ch = false;
    }
    if (ch)ct++;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)cin >> h[i + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])dfs(i);
    cout << ct << endl;
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