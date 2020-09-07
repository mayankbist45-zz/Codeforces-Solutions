#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


int dist[maxn], n;
vector<int> g[maxn];

void dfs(int u, int p = -1) {
    for (auto x : g[u]) {
        if (x == p)continue;
        dist[x] = 1 + dist[u];
        dfs(x, u);
    }
}


void solve() {
    int a, b, da, db;
    cin >> n >> a >> b >> da >> db;

    for (int i = 0; i <= n; i++)g[i].clear();
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (da + 1 >= db) {
        cout << "Alice" << endl;
        return;
    }
    if (db < 2 * da + 1) {
        cout << "Alice" << endl;
        return;
    }
    dist[a] = 0;
    dfs(a);
    if (dist[b] <= da) {
        cout << "Alice" << endl;
        return;
    }
    int mx = -1, id = -1;
    for (int i = 1; i <= n; i++)if (dist[i] > mx)mx = dist[i], id = i;
    dist[id] = 0;
    dfs(id);
    int dia = *max_element(dist + 1, dist + n + 1);
    if ((dia + 1) / 2 <= da) {
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
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