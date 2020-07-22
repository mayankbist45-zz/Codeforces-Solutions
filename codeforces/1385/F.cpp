#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<set<int>> g, l;

struct comp {
    bool operator()(int a, int b) const {
        if (l[a].size() == l[b].size())return a < b;
        return l[a].size() > l[b].size();
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    g = l = vector<set<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].insert(b);
        g[b].insert(a);
    }
    set<int, comp> st;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)l[*g[i].begin()].insert(i);
    for (int i = 1; i <= n; i++)st.insert(i);
    int ans = 0;
    while (true) {
        int node = *st.begin();
        if (l[node].size() < k)break;
        for (int i = 0; i < k; i++) {
            int lf = *l[node].begin();

            g[lf].erase(node);
            g[node].erase(lf);

            st.erase(node);
            st.erase(lf);

            l[node].erase(lf);
            if (l[lf].count(node))l[lf].erase(node);

            if (g[node].size() == 1) {
                int to = *g[node].begin();
                st.erase(to);
                l[to].insert(node);
                st.insert(to);
            }
            st.insert(node);
            st.insert(lf);
        }
        ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}