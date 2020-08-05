#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<pair<int, int>> g[maxn];
int par[maxn], wt[maxn], wt1[maxn];
int n, s;

int dfs(int u, int p, int w) {
    wt[u] = w;
    par[u] = p;
    int ct = 0;
    bool lf = true;
    for (auto x : g[u]) {
        if (x.first != p) {
            lf = false;
            ct += dfs(x.first, u, x.second);
        }
    }
    wt1[u] = ct + lf;
    return ct + lf;
}

int check() {
    int ct = 0;
    int sum = 0;

    priority_queue<pair<pair<int, int>, int>> pq;

    for (int i = 1; i <= n; i++) {
        int ele = i;
        pq.push({{(wt[ele] + 1) / 2 * wt1[ele], wt1[ele]}, ele});
        sum += wt[ele] * wt1[ele];
    }

    while (sum > s) {
        ct++;
        auto top = pq.top();
        pq.pop();

        sum -= top.first.first;
        wt[top.second] = wt[top.second] / 2;
        pq.push({{(wt[top.second] + 1)/2 * wt1[top.second], wt1[top.second]}, top.second});
    }
    return ct;
}

void solve() {
    cin >> n >> s;

    for (int i = 0; i <= n; i++)g[i].clear(), par[i] = 0, wt[i] = 0, wt1[i] = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(1, -1, 0);
    cout << check() << endl;
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