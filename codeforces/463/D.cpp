#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> g[maxn];
int deg[maxn], dp[maxn];
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k, vector<int>(n));
    for (auto &x: v)
        for (auto &j: x)
            cin >> j;
    for (int i = 1; i <= n; i++) {
        int ct = 0;
        set<int> a, b;
        bool time = false;
        for (auto x: v) {
            bool fd = false;
            for (int j = 0; j < x.size(); j++) {
                if (!time and fd)b.insert(x[j]);
                else if (time and a.count(x[j]) and fd)b.insert(x[j]);
                if (x[j] == i)fd = true;
            }
            time = true;
            a = b;
            b.clear();
        }
        for (auto x: a)g[i].push_back(x), deg[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i])q.push(i), dp[i] = 1;
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto x: g[top]) {
            deg[x]--;
            dp[x] = max(dp[x], 1 + dp[top]);
            if (!deg[x])q.push(x);
        }
    }
    cout << *max_element(dp + 1, dp + n + 1) << endl;
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