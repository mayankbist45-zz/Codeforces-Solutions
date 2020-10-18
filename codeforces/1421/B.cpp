#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    vector<pair<int, int>> ans;
    map<char, int> mp;
    mp[v[0][1]]++;
    mp[v[1][0]]++;
    mp[v[n - 2][n - 1]]++;
    mp[v[n - 1][n - 2]]++;
    if (v[0][1] == v[1][0]) {
        if (v[n - 1][n - 2] == v[1][0])ans.push_back({n, n - 1});
        if (v[n - 2][n - 1] == v[1][0])ans.push_back({n - 1, n});
    } else if (v[0][1] != v[1][0]) {
        if (v[n - 1][n - 2] == v[n - 2][n - 1]) {
            if (v[n - 1][n - 2] == v[0][1])ans.push_back({1, 2});
            if (v[n - 1][n - 2] == v[1][0])ans.push_back({2, 1});
        } else {
            ans.push_back({n, n - 1});
            if (v[n - 1][n - 2] != v[0][1])ans.push_back({1, 2});
            if (v[n - 1][n - 2] != v[1][0])ans.push_back({2, 1});
        }
    }
    cout << ans.size() << endl;
    for (auto x: ans)cout << x.first << " " << x.second << endl;
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

