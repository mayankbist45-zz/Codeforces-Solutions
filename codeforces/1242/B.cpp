#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_set<int, custom_hash> st;
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
    cout << comp.size() - 1 << endl;
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
