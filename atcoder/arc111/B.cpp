#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 400010
const int MOD = 1000000007;

vector<int> g[maxn], comp;
int visited[maxn], fl[maxn];

void dfs(int u) {
    comp.push_back(u);
    visited[u] = true;
    for (auto x : g[u])
        if (!visited[x])
            dfs(x);
}

void solve() {
    int n;
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        st.insert(a);
        st.insert(b);

        if (a == b) {
            fl[a] = 1;
            continue;
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (auto x:st) {
        if (!visited[x]) {
            comp.clear();
            dfs(x);

            int edges = 0, done = 0;
            for (auto node: comp) {
                if (fl[node]) {
                    done = 1;
                    ans += comp.size();
                    break;
                }
                edges += g[node].size();
            }
            if (!done) {
                if (edges / 2 + 1 == comp.size())ans += comp.size() - 1;
                else ans += comp.size();
            }
        }
    }
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