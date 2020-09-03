#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
int n, a[maxn], sum[maxn], dist[maxn], dp[maxn], tot;

//dp[i] contribution of ith subtree in the whole answer
void dfs(int u, int p = -1) {
    sum[u] = a[u];
    dp[u] = dist[u] * a[u];
    for (auto x : g[u]) {
        if (x == p)continue;
        dist[x] = 1 + dist[u];
        dfs(x, u);
        dp[u] += dp[x];
        sum[u] += sum[x];
    }
}

int ans = 0;

void change_root(int u, int v) {
    dp[u] -= dp[v];
    dp[v] -= sum[v];
    sum[u] -= sum[v];
    dp[u] += sum[u];
    sum[v] += sum[u];
    dp[v] += dp[u];
}

void walk(int u, int p = -1) {
    ans = max(ans, dp[u]);
    for (auto x: g[u]) {
        if (x == p) continue;
        change_root(u, x);
        walk(x, u);
        change_root(x, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i + 1], tot += a[i + 1];
    for (int i = 0, A, B; i < n - 1; i++) {
        cin >> A >> B;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    dfs(1);
    walk(1);
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