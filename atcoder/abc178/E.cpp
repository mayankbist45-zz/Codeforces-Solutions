#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int mand(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first + a.second < b.first + b.second;
    });
    int ans = mand(v[0], v.back());
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first - a.second < b.first - b.second;
    });
    ans = max(ans, mand(v[0], v.back()));
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
