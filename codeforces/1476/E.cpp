#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
int visited[maxn];
vector<int> order;


bool dfs(int u) {
    visited[u] = 1;
    for (auto x : g[u]) {
        if (!visited[x]) {
            bool ans = dfs(x);
            if (ans)return ans;
        } else if (visited[x] == 1)return true;
    }
    visited[u] = 2;
    order.push_back(u);
    return false;
}


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> pat(n);
    vector<pair<int, string>> str(m);

    int id = 0;
    map<string, int> index;

    for (auto &x: pat)cin >> x, index[x] = id++;
    set<string> st(pat.begin(), pat.end());
    for (auto &x: str)cin >> x.second >> x.first, x.first -= 1;

    for (auto x: str) {
        vector<string> cand;
        bool fd = false;
        for (int i = 0; i < (1 << k); i++) {
            string now;
            for (int j = 0; j < k; j++) {
                if (i >> j & 1)now += x.second[j];
                else now += '_';
            }
            if (st.count(now)) cand.push_back(now);
        }

        if (cand.empty()) {
            cout << "NO" << endl;
            return;
        }

        for (auto cur: cand) {
            if (cur == pat[x.first]) {
                fd = true;
                continue;
            }
            g[x.first].push_back(index[cur]);
        }
        if (!fd) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    reverse(order.begin(), order.end());
    cout << "YES" << endl;
    for (auto x: order)cout << x + 1 << " ";
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