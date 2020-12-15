#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int n, ans;
vector<int> g[maxn];

int dfs(int u, int p = -1) {
    if (g[u].size() == 1 and u != 1)return 1;
    vector<int> v;
    for (auto x: g[u]) {
        if (x == p)continue;
        v.push_back(dfs(x, u));
    }
    sort(v.begin(), v.end());
    if (v.size() > 1) {
        if (u != 1)ans = max(ans, v.back() + 1);
        else ans = max({ans, v.back(), v[v.size() - 2] + 1});
    }
    ans = max(ans, v[0]);
    return v[0] + 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++)g[i].clear();
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 0;
    dfs(1, -1);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}