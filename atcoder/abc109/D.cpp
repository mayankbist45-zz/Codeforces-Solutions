#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h, vector<int>(w));
    int ct = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    using pii = pair<int, int>;
    vector<pair<pii, pii>> ans;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (i + 1 < h and v[i][j] & 1) {
                v[i][j]--, v[i + 1][j]++;
                ans.push_back({{i,     j},
                               {i + 1, j}});
            }
        }

    for (int j = 0; j < w; j++) {
        if (j + 1 < w and v[h - 1][j] & 1) {
            v[h - 1][j]--, v[h - 1][j + 1]++;
            ans.push_back({{h - 1, j},
                           {h - 1, j + 1}});
        }
    }

    cout << ans.size() << endl;
    for (auto x: ans) {
        cout << x.first.first + 1 << " " << 1 + x.first.second << " " << 1 + x.second.first << " "
             << 1 + x.second.second;
        cout << endl;
    }
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