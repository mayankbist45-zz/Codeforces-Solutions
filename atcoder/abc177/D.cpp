#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int visited[maxn];
set<int> g[maxn];

int dfs(int u) {
    int cur = 1;
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            cur += dfs(x);
        }
    }
    return cur;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            ans = max(ans, dfs(i));
    }
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