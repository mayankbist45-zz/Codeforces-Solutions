#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int v[maxn], n;

int Lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

pair<int, int> dfs(int u, int p = -1) {
    vector<pair<int, int>> res;
    int lc = 1;
    for (auto x : g[u]) {
        if (x == p)continue;
        auto tp = dfs(x, u);
        res.push_back(tp);
        lc = Lcm(lc, tp.second);
    }
    if (res.empty())return {v[u], 1};
    int mn = LLONG_MAX;
    for (auto x: res) mn = min(mn, x.first / lc * lc);
    return {mn * (int) res.size(), max(1ll, (int) res.size() * lc)};
}

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> v[i + 1], sum += v[i + 1];
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << sum - dfs(1, -1).first << endl;
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