#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
int a[maxn], n, now[maxn];
int ans = 0;
void dfs(int u, int p = -1) {
    bool lf = true;
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs(x, u);
        lf = false;
        now[u] += now[x];
        a[u] += a[x];
    }
    if (lf)now[u] = 1;
    ans = max(ans, a[u] / now[u] + (a[u] % now[u] > 0));
}
void solve() {
    cin >> n;
    for (int i = 0, tp; i < n - 1; i++) {
        cin >> tp;
        g[tp].push_back(i + 2);
    }
    for (int i = 0; i < n; i++)cin >> a[i + 1];
    dfs(1);
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