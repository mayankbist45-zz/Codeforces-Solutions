#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 110
const int MOD = 1000000007;

int val[maxn], di[maxn][maxn];

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> v(n + 1);
    for (int i = 2; i < n; i++)cin >> val[i];
    for (int i = 1; i <= n; i++)cin >> v[i].first >> v[i].second;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i != j)
                di[i][j] = dist(v[i], v[j]) * d - val[j];
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                di[i][j] = min(di[i][j], di[i][k] + di[k][j]);
    cout << di[1][n] << endl;
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