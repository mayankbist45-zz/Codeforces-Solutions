#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int lo = 1, hi = 1e9, mid, ans = 0;
    auto check = [&](const int &val) -> bool {
        int ct = 0, sal = 0;
        vector<pair<int, int>> cur;
        for (auto &x: v) {
            if (x.second < val)sal += x.first;
            else if (x.first > val)sal += x.first, ct++;
            else cur.push_back(x);
        }
        if ((n + 1) / 2 > ct + cur.size())return false;
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        for (auto x: cur) {
            if (ct < (n + 1) / 2)sal += val, ct++;
            else sal += x.first;
        }
        return sal <= s;
    };

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