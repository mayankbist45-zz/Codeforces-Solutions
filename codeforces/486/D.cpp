#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

int a[maxn], dp1[maxn];
vector<int> g[maxn], visited;
int d, n, cur;

void dfs(int u, int val) {
    visited[u] = true;
    dp1[u] = 1;
    for (auto x : g[u]) {
        if (!visited[x] and a[x] >= val and a[x] <= val + d) {
            if(a[x] == val and x < cur)continue;
            dfs(x, val);
            dp1[u] *= (1 + dp1[x]);
            dp1[u] %= MOD;
        }
    }
}

void solve() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        visited = vector<int>(n + 1);
        cur = i;
        dfs(i, a[i]);
        ans += dp1[i];
        if (ans >= MOD)ans -= MOD;
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