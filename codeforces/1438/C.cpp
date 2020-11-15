#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, m;
int w, b;
vector<vector<int>> v;
void solve() {
    cin >> n >> m;
    v = vector<vector<int>>(n, vector<int>(m));
    for (auto &x: v)
        for (auto &j: x)cin >> j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i & 1) {
                if (j & 1)v[i][j] = (v[i][j] & 1) ? v[i][j] : v[i][j] + 1;
                else v[i][j] = (v[i][j] & 1) ? v[i][j] + 1 : v[i][j];
            } else {
                if (j % 2 == 0)v[i][j] = (v[i][j] & 1) ? v[i][j] : v[i][j] + 1;
                else v[i][j] = (v[i][j] & 1) ? v[i][j] + 1 : v[i][j];
            }
        }
    }
    for (auto &x: v) {
        for (auto &j: x)
            cout << j << " ";
        cout << endl;
    }
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