#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int visited[maxn], dist[maxn], pa[maxn];

void bfs(int src) {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node])
            if (!visited[x]) {
                dist[x] = 1 + dist[node];
                q.push(x);
                pa[x] = node;
                visited[x] = true;
            }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
    for (int i = 2; i <= n; i++)
        if (dist[i] == -1) {
            cout << "No";
            return;
        }
    cout << "Yes" << endl;
    for (int i = 2; i <= n; i++)cout << pa[i] << endl;
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