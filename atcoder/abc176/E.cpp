#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int h, w, m;
    cin >> h >> w >> m;

    vector<pair<int, int>> v(m);
    set<pair<int, int>> st;
    int mx = 0, id = -1;
    int mx1 = 0, id1 = -1;
    map<int, int> row, col;
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        row[v[i].first]++;
        col[v[i].second]++;
        if (mx < col[v[i].second]) {
            mx = max(mx, col[v[i].second]);
            id = v[i].second;
        }
        if (mx1 < row[v[i].first]) {
            mx1 = row[v[i].first];
            id1 = v[i].first;
        }
        st.insert(v[i]);
    }
    int ans = 0;
    for (int i = 1; i <= 300000; i++) {
        if (st.find({i, id}) != st.end())ans = max(ans, row[i] + mx - 1);
        else ans = max(ans, row[i] + mx);
    }
    for (int i = 1; i <= 300000; i++) {
        if (st.find({id1, i}) != st.end())ans = max(ans, col[i] + mx1 - 1);
        else ans = max(ans, col[i] + mx1);
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