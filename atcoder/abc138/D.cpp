#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
int val[maxn];
int visited[maxn];

void dfs(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            val[x] += val[u];
            dfs(x);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        val[a] += b;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)cout << val[i] << " ";
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