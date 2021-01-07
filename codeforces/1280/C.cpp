#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<int, int>> g[maxn];
int k, val1 = 0, val2 = 0;

int sz[maxn];
void gfs(int u, int p = -1) {
    sz[u] = 1;
    for (auto x : g[u]) {
        if (x.first == p)continue;
        gfs(x.first, u);
        val1 += (sz[x.first] & 1) * x.second;
        val2 += min(sz[x.first], 2 * k - sz[x.first]) * x.second;
        sz[u] += sz[x.first];
    }
}

void solve() {
    val1 = val2 = 0;
    cin >> k;
    for (int i = 0; i <= 2 * k + 1; i++)sz[i] = 0;

    for (int i = 0; i <= 2 * k; i++)
        g[i].clear();
    for (int i = 0; i < 2 * k - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    gfs(1);
    cout << val1 << " " << val2 << endl;
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