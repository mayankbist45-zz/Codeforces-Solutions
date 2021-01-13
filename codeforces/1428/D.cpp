#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void done() {
    cout << -1;
    exit(0);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i + 1];
    }
    vector<pair<int, int>> val[4];
    vector<pair<int, int>> ans;

    int row = n;
    for (int i = n; i > 0; i--) {
        if (v[i] == 1) {
            if (!row)done();
            val[1].push_back({row, i});
            ans.push_back({row, i});
            row--;
        } else if (v[i] == 2) {
            if (val[1].empty())done();
            ans.push_back({val[1].back().first, i});
            val[2].push_back({val[1].back().first, i});
            val[1].pop_back();
        } else if (v[i] == 3) {
            if (!row)done();
            auto solve = [&](vector<pair<int, int>> &some) {
                int col = some.back().second;
                ans.push_back({row, i});
                ans.push_back({row, col});
                some.pop_back();
                val[3].push_back({row, i});
            };
            bool fd = false;
            for (int id = 3; id >= 1; id--) {
                if (!val[id].empty()) {
                    solve(val[id]);
                    fd = true;
                    break;
                }
            }
            if (!fd)done();
            row--;
        }
    }
    cout << ans.size() << endl;
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