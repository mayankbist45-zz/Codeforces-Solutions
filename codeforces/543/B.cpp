#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 3010
const int MOD = 1000000007;

vector<int> g[maxn];
int n, m;
int s1, t1, l1;
int s2, t2, l2;

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto x : g[node])
                if (dist[i][x] == -1) {
                    dist[i][x] = 1 + dist[i][node];
                    q.push(x);
                }
        }
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    int ans = m + 1;
    for (int it = 0; it < 2; it++) {
        swap(s1, t1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                int d1 = dist[s1][i] + dist[i][j] + dist[j][t1];
                int d2 = dist[s2][i] + dist[i][j] + dist[j][t2];

                if (d1 <= l1 and d2 <= l2)ans = min(ans, d1 + d2 - dist[i][j]);
            }
    }
    if (dist[s1][t1] <= l1 and dist[s2][t2] <= l2)ans = min(ans, dist[s1][t1] + dist[s2][t2]);
    if (ans > m)ans = -1;
    else ans = m - ans;
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