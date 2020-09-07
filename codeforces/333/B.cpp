#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
int n, m;
map<int, int> row, col;

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0, a, b; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        row[v[i].first]++;
        col[v[i].second]++;
    }
    int ans = 0;
    for (int i = 2; i <= (n + 1) / 2; i++) {
        if (i == n - i + 1){
            if(row[i] == 0)ans++;
            else if(col[i] == 0)ans++;
            continue;
        }
        int cur = 0;
        if (row[i] > 0)cur++;
        if (row[n - i + 1] > 0)cur++;
        if (col[i] > 0)cur++;
        if (col[n - i + 1] > 0)cur++;

        ans += 4 - cur;
    }
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