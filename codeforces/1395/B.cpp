#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;
 
int vis[maxn][maxn];
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    int sx, sy;
    cin >> sx >> sy;
 
    vis[sx][sy] = 1;
    cout << sx << " " << sy << endl;
 
    vector<pair<int, int>> ans;
    if (sx != 1)sx = 1, vis[sx][sy] = 1, ans.push_back({sx, sy});
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> pans;
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j])pans.push_back({i, j}), vis[i][j] = true;
        }
        if (i % 2 == 0)reverse(pans.begin(), pans.end());
        for (auto x: pans)ans.push_back(x);
    }
    for (auto x: ans)cout << x.first << " " << x.second << endl;
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