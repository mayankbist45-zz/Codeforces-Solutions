#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int visited[maxn];
vector<int> g[maxn];

void dfs(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)if (!visited[i])dfs(i), ans++;
    cout << ans - 1 << endl;
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