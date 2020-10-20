#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];

template<typename T>
void make_set(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

map<int, int> bfs(int src) {
    map<int, int> dist;
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node])
            if (!dist.count(x)) {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
    }
    return dist;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    //no three are common means common atmost 2 bit
    // for(1, 61) at most 2 values

    vector<pair<int, int>> edges;
    for (int i = 61; i >= 0; i--) {
        int ct = 0;
        vector<int> val;
        for (int j = 0; j < n; j++) {
            int x = v[j];
            if ((x >> i) & 1)
                ct++, val.push_back(j);
        }
        if (ct > 2) {
            cout << 3 << endl;
            return;
        }
        if (val.size() == 2) {
            g[val.front()].push_back(val.back());
            g[val.back()].push_back(val.front());
            edges.push_back(minmax(val.back(), val.front()));
        }
    }
    make_set(edges);
    for (int i = 0; i < n; i++) make_set(g[i]);
    int ans = LLONG_MAX;
    for (auto x: edges) {
        g[x.first].erase(find(g[x.first].begin(), g[x.first].end(), x.second));
        g[x.second].erase(find(g[x.second].begin(), g[x.second].end(), x.first));

        map<int, int> mp = bfs(x.first);
        if (mp.count(x.second))ans = min(ans, 1 + mp[x.second]);
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }
    if (ans == LLONG_MAX)ans = -1;
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