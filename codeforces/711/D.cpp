#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

/*
 * there are exactly n edges
 * dfs tree will have exactly one back edge
 * let's say the edges are not directed
 * no of ways to make each edge directed such that
 * there exists no cycle
 *
 * let's find the only cycle
 * can there be more than one cycle? no
 *
 * and now no of nodes in this cycle is x then ans = 2 ^ (n - x) * something
 * now here for each edge we can flip them 2 ^ x times and out of them 2 ways are
 * invalid which are pure cycles so we remove them
 *
 * something  = 2 ^ x - 2
 * ans = 2 ^ (n - x) * (2 ^ x - 2)
 *
 * hopefully!
 *
 */
int visited[maxn], dep[maxn];
vector<int> g[maxn];

int pw(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}

int mx = 0;
int dfs(int u) {
    visited[u] = 1;
    int ans = 1;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dep[x] = 1 + dep[u];
            ans += dfs(x);
        } else if (visited[x] == 1)
            mx = max(mx, dep[u] - dep[x] + 1);
    }
    visited[u] = 2;
    return ans;
}
void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        g[i].push_back(v[i]);
        g[v[i]].push_back(i);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            mx = 0;
            int tot = dfs(i) - (mx == 0);
            ans = (ans * pw(2, tot - mx)) % MOD;
            int coeff = pw(2, mx) - 2;
            if (coeff < 0)coeff += MOD;
            (ans *= coeff) %= MOD;
        }
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