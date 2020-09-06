#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int v[maxn], n;

template<class T>
T gcd(T a, T b) {
    T t;
    while (a) {
        t = a;
        a = b % a;
        b = t;
    }
    return b;
}

int Lcm(int x, int y) {
    int g = gcd(x, y);
    if (1.0 * x * y / g > 1e14)
        return 1e14;
    return x / g * y;
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
    return {mn * (int) res.size(), (int) res.size() * lc};
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