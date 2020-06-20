#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int p[maxn], c[maxn];
vector<int> g[maxn];

void dfs(int u, int pp = -1) {
    p[u] = pp;
    for (auto x : g[u])
        if (x != pp)
            dfs(x, u);
}

int visited[maxn];

void dfs2(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x] and (c[x] == c[u] or c[x] == 0)) {
            c[x] = c[u];
            dfs2(x);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);

    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
    for (int i = 0, j = (int) path.size() - 1; i < j;) {
        c[path[i]] = 1;
        i++;
        c[path[j]] = 2;
        j--;
        if (i == j) {
            c[path[i]] = 1;
            break;
        }
    }
    for (auto x: path)
        if (!visited[x])
            dfs2(x);
    int b = 0, w = 0;
    for (int i = 1; i <= n; i++)
        b += (c[i] == 1), w += (c[i] == 2);

//    cout << b << " " << w << endl;
    if (b > w)cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
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

