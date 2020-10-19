#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
vector<int> bfs(int src, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node])
            if (dist[x] == -1) {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
    }
    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++)cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> l = bfs(1, n), r = bfs(n, n);
    vector<pair<int, int>> val;
    for (int i = 1; i <= n; i++) {
        if (binary_search(v.begin(), v.end(), i))
            val.push_back({l[i], r[i]});
    }
    sort(val.begin(), val.end(), [](auto &a, auto &b) {
        return a.first - a.second < b.first - b.second;
    });
    int mx = val.back().second, ans = 0;
    for (int i = (int)val.size() - 2; i >= 0; i--) {
        ans = max(ans, val[i].first + mx);
        mx = max(mx, val[i].second);
    }
    cout << min(ans + 1, l[n]) << endl;
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