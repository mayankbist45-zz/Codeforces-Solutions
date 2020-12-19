#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<bool> big(maxn + 1), isBigger(maxn + 1), vis(maxn);
vector<int> g[maxn], ans;
void done() {
    cout << "No";
    exit(0);
}

void dfs(int u) {
    vis[u] = 1;
    ans.push_back(u);
    if (isBigger[u])done();
    for (auto x : g[u]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);
    for (auto &x: v) {
        int sz;
        cin >> sz;
        x = vector<int>(sz);
        for (auto &j: x)cin >> j;
    }

    auto checkLexic = [](vector<int> &a, vector<int> &b) {
        int id = -1;
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i]) {
                id = i;
                break;
            }
        }
        if (id == -1 and a.size() > b.size())done();
        if (id == -1)return;

        if (a[id] < b[id])g[b[id]].push_back(a[id]);
        else {
            big[a[id]] = 1;
            isBigger[b[id]] = 1;
        }
    };
    for (int i = 1; i < n; i++) checkLexic(v[i - 1], v[i]);
    for (int i = 1; i <= m; i++) {
        if (!vis[i] and big[i]) {
            dfs(i);
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto x: ans) {
        cout << x << " ";
    }
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