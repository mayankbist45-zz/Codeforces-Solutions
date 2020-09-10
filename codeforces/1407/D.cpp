#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

int dist[maxn];
vector<int> g[maxn];

void bfs(int src) {
    memset(dist, -1, sizeof dist);
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
}

void clean(stack<pair<int, int>> &st) {
    while (!st.empty())st.pop();
}

void solve() {
    int n;
    cin >> n;

    stack<pair<int, int>> st1, st2;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];

        while (!st1.empty() and st1.top().first > v[i]) st1.pop();
        if (!st1.empty())g[st1.top().second].push_back(i);
        st1.push({v[i], i});


        while (!st2.empty() and st2.top().first < v[i]) st2.pop();
        if (!st2.empty())g[st2.top().second].push_back(i);
        st2.push({v[i], i});
    }
    clean(st1);
    clean(st2);

    for (int i = n; i >= 1; i--) {
        while (!st1.empty() and st1.top().first > v[i]) st1.pop();
        if (!st1.empty())g[i].push_back(st1.top().second);
        st1.push({v[i], i});


        while (!st2.empty() and st2.top().first < v[i]) st2.pop();
        if (!st2.empty())g[i].push_back(st2.top().second);
        st2.push({v[i], i});
    }

    bfs(1);
    cout << dist[n] << endl;
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