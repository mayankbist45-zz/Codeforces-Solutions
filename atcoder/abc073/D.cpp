#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;

int g[maxn][maxn];
constexpr int INF = INT_MAX;

void solve() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> p(r);
    for (int i = 0; i < r; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < maxn; i++)for (int j = 0; j < maxn; j++)if (i != j)g[i][j] = INF;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = g[b][a] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
    }
    int pasn = LLONG_MAX;
    do {
        int ans = 0;
        for (int i = 1; i < r; i++)
            ans += g[p[i - 1]][p[i]];
        pasn = min(pasn, ans);
    } while (next_permutation(p.begin(), p.end()));
    cout << pasn << endl;
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