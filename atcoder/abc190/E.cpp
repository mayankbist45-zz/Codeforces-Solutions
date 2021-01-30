#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;


vector<int> g[maxn];
void bfs(int src, vector<int> &dist) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto x : g[node])
            if (dist[x] == -1) {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
    }
}

int n, m;
vector<int> c;
int k;

map<int, vector<int>> mp;
int dp[20][(1 << 17)];
int solve(int pos, int mask) {
    if (__builtin_popcountll(mask) == k)return 0;
    vector<int> &di = mp[c[pos]];

    int &ans = dp[pos][mask];
    if (ans != -1)return ans;
    ans = INT_MAX;
    for (int i = 0; i < k; i++) {
        if (mask >> i & 1)continue;
        if (di[c[i]] == -1)continue;
        ans = min(ans, di[c[i]] + solve(i, mask | (1 << i)));
    }
    return ans;
}


void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    vector<pair<int, int>> v(m);
    for (auto &x: v) {
        cin >> x.first >> x.second;
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }
    cin >> k;

    int ans = LLONG_MAX;

    c = vector<int>(k);
    for (auto &x: c)cin >> x;

    for (int start = 0; start < k; ++start) {
        vector<int> di(n + 1, -1);
        bfs(c[start], di);
        mp[c[start]] = di;
    }
    auto &cur = mp[c.front()];
    for (int i = 1; i < k; i++) {
        if (cur[c[i]] == -1) {
            cout << -1;
            return;
        }
    }
    for (int i = 0; i < k; i++) {
        ans = min(ans, solve(i, (1 << i)));
    }
    cout << ans + 1 << endl;
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