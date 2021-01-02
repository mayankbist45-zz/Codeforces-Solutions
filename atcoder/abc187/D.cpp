#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    int aoki = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        aoki += v[i].first;
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first * 2 + a.second == b.first * 2 + b.second)
            return a.first > b.first;
        return a.first * 2 + a.second > b.first * 2 + b.second;
    });
    int now = 0, now2 = aoki, ans = 0;
    for (int i = 0; i < n; i++) {
        if (now > now2)break;
        ans++;
        now += v[i].first + v[i].second;
        now2 -= v[i].first;
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