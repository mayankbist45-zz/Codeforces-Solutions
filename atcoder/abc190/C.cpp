#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    int k;
    cin >> k;

    vector<pair<int, int>> ball(k);
    for (auto &x: ball)cin >> x.first >> x.second;

    map<int, int> count;
    int mx = 0;
    for (int bit = 0; bit < (1 << k); bit++) {
        for (int i = 0; i < k; i++) {
            if (bit >> i & 1)count[ball[i].second]++;
            else count[ball[i].first]++;
        }
        int tp = 0;
        for (auto x: v) {
            if (count[x.first] and count[x.second]) {
                tp++;
            }
        }
        mx = max(mx, tp);

        for (int i = 0; i < k; i++) {
            if (bit >> i & 1)count[ball[i].second]--;
            else count[ball[i].first]--;
        }
    }
    cout << mx << endl;
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