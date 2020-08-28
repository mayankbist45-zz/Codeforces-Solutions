#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

set<int> g[maxn];
int ans;
int n;

int dist[maxn];

void bfs(int src, int nod) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    dist[nod] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node])
            if (dist[x] == -1) {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
    }
}

int max_dist(int val, int node) {
    bfs(val, node);
    int id = -1, mx = 0;
    for (int i = 1; i <= n; i++)if (dist[i] != -1 and dist[i] > mx)mx = dist[i], id = i;
    if (id != -1)bfs(id, node);
    return max(0ll, *max_element(dist + 1, dist + n + 1));
}

int getdia(int a, int b) {
    int val = max_dist(a, b) * max_dist(b, a);
    return val;
}

void dfs(int u, int p = -1) {
    for (auto x : g[u]) {
        if (x != p) {
            ans = max(ans, getdia(x, u));
            dfs(x, u);
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

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