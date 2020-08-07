#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n;
vector<pair<int, int>> vp;

bool check(int dist) {
    vector<int> ty(n);
    int id = 0;
    for (auto x: vp) {
        int ct = x.first;
        for (int i = id; i < n and ct > 0; i += dist + 1) {
            ty[i] = x.second;
            ct--;
        }
        if (ct)return false;
        id++;
    }
    return true;
}

void solve() {
    vp.clear();
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto x: mp)vp.push_back({x.second, x.first});
    sort(vp.rbegin(), vp.rend());
    int lo = 0, hi = n - 2, mid, ans = 0;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    cout << ans << endl;
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