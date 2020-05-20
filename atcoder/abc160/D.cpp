#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];

void bfs(int src, vector<int> &dist, vector<bool> &visited) {
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
                visited[x] = true;
            }
    }
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 2; i <= n; i++) {
        g[i].push_back(i - 1);
        g[i - 1].push_back(i);
    }

    g[x].push_back(y);
    g[y].push_back(x);

    map<int, int> an;
    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1);
        vector<bool> visited(n + 1);
        bfs(i, dist, visited);
        for (int j = 1; j <= n; j++) {
            if (j == i)continue;
            an[dist[j]]++;
        }
    }
    for (int i = 1; i <= n - 1; i++)cout << an[i]/2 << endl;
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