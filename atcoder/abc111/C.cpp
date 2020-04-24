#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)cin >> v[i];

    map<int, int> mp, mp2;
    for (int i = 0; i < n; i += 2)
        mp[v[i]]++;
    for (int i = 1; i < n; i += 2)
        mp2[v[i]]++;

    vector<pair<int, int>> v1, v2;

    for (auto x: mp)v1.emplace_back(x);
    for (auto x: mp2)v2.emplace_back(x);

    sort(v1.begin(), v1.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    sort(v2.begin(), v2.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    int id1 = 0, id2 = 0;
    if (v1[id1].first == v2[id2].first) {
        if (v1[id1].second > v2[id2].second)
            id2++;
        else if (v1[id1].second == v2[id2].second) {
            int tp1 = id1 + 1, tp2 = id2 + 1, n1 = 0, n2 = 0;
            if (tp1 < v1.size())n1 = v1[tp1].second;
            if (tp2 < v2.size())n2 = v2[tp2].second;
            if (n1 > n2)id1++;
            else id2++;
        } else
            id1++;
    }
    int ans = 0;
    if (id1 >= v1.size())
        ans += n / 2;
    else
        ans += n / 2 - v1[id1].second;
    if (id2 >= v2.size())
        ans += n / 2;
    else
        ans += n / 2 - v2[id2].second;
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