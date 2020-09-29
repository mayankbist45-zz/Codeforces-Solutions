#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 500010
const int MOD = 1000000007;

set<int> st;
vector<int> g[maxn];
int n, m;
vector<vector<int>> comp;

void dfs(int u) {
    comp.back().push_back(u);
    st.erase(u);
    bool fl = true;
    while (fl) {
        fl = false;
        for (auto x: st) {
            if (binary_search(g[u].begin(), g[u].end(), x))continue;
            dfs(x);
            fl = true;
            break;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; i++)st.insert(i);
    for (int i = 1; i <= n; i++)
        if (st.count(i)) {
            comp.emplace_back();
            dfs(i);
        }
    cout << comp.size() << endl;
    for (auto x: comp) {
        cout << x.size() << " ";
        for (auto prt: x)cout << prt << " ";
        cout << endl;
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
