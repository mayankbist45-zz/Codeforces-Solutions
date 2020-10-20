#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());
    vector<pair<int, int>> cur;
    cur.push_back(v.back());
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        bool fd = false;
        for (auto x: cur) {
            if (x.first != v[i].first) {
                ans.push_back({x.second, v[i].second});
                cur.push_back(v[i]);
                fd = true;
                break;
            }
        }
        if (!fd) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto x: ans)cout << 1 + x.first << " " << 1 + x.second << endl;
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