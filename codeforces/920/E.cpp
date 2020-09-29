#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

set<int> g[maxn], st;
int n, m;

int dfs(int u) {
    int ans = 1;
    st.erase(u);
    bool fl = true;
    while (fl) {
        fl = false;
        for (auto x: st) {
            if (g[u].count(x))continue;
            ans += dfs(x);
            fl = true;
            break;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 1; i <= n; i++)st.insert(i);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (st.count(i))
            ans.push_back(dfs(i));
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x: ans)cout << x << " ";
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