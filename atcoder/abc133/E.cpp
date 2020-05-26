#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int n, k;

int dfs(int u, int p = -1) {
    int init, ans = 1;
    if (p == -1)init = k - 1;
    else init = k - 2;

    if (init + 1 < g[u].size())
        return 0;
    for (auto x : g[u]) {
        if (x != p) {
            ans *= init--;
            ans %= MOD;
            ans *= dfs(x, u);
            ans %= MOD;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << (k * dfs(1)) % MOD << endl;
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