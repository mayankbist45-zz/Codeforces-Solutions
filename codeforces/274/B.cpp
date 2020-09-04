#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int v[maxn];

vector<int> g[maxn];
int dp[maxn], ans;

pair<int, int> dfs(int u, int p = -1) {
    int mx1 = 0, mx2 = 0;
    for (auto x : g[u]) {
        if (x == p)continue;
        auto tp = dfs(x, u);
        mx1 = max(tp.first, mx1);
        mx2 = max(tp.second, mx2);
    }
    v[u] -= mx1;
    v[u] += mx2;

    if (v[u] > 0)mx1 += v[u];
    else mx2 += abs(v[u]);
    return {mx1, mx2};
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) cin >> v[i];
    auto tp = dfs(1);
    cout << tp.first + tp.second << endl;
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