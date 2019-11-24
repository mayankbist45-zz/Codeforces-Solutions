#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

vector<int> g[maxn];
int ans[maxn];
map<pair<int, int>, int> mp;
int k = 0;

void dfs(int u, int p = -1, int prev = -1) {
    int color = 1;
    for (auto x: g[u]) {
        if (color == prev)
            color++;
        if (ans[mp[{min(u, x), max(u, x)}]] == 0)
            ans[mp[{min(u, x), max(u, x)}]] = color, color++;
    }
    for (auto x : g[u]) {
        if (x != p) {
            dfs(x, u, ans[mp[{min(u, x), max(u, x)}]]);
        }
    }
    k = max(k, color);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
        if (a > b)swap(a, b);
        mp[{a, b}] = i;
    }

    dfs(1);
    cout << k -1 << endl;
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << endl;
}