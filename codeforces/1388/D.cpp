#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];
vector<int> order;
int visited[maxn];

void dfs(int u) {
    visited[u] = true;
    for (auto x : g[u]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
    order.push_back(u);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), b(n), z(n);
    for (int i = 0; i < n; i++)cin >> v[i], z[i] = v[i];
    for (int i = 0; i < n; i++)cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (b[i] != -1)g[i].push_back(b[i] - 1);
    }
    int ans = 0;
    vector<int> an, an2;
    for (int i = 0; i < n; i++)if (!visited[i])dfs(i);
    reverse(order.begin(), order.end());

    for (auto &i: order) {
        ans += v[i];
        if (b[i] != -1 and v[i] > 0)
            v[b[i] - 1] += v[i], an.push_back(i);
        else if (b[i] == -1)an.push_back(i);
        else an2.push_back(i);
    }
    reverse(an2.begin(), an2.end());
    cout << ans << endl;

    int sum = 0;
    for (auto x: an) {
        sum += z[x];
        if (b[x] != -1)z[b[x] - 1] += z[x];
        cout << x + 1 << " ";
    }
    for (auto x: an2) {
        sum += z[x];
        if (b[x] != -1)z[b[x] - 1] += z[x];
        cout << x + 1 << " ";
    }
    assert(sum == ans);
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