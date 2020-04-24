#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int visited[2 * maxn + 100];
vector<int> g[2 * maxn + 100];

void dfs(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int tp;
            cin >> tp;
            tp += maxn;
            g[i].push_back(tp);
            g[tp].push_back(i);
        }
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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