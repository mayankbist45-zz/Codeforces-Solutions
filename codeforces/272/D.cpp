#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int m;

int fact(int n, int &del) {
    int cur = 1;
    while (n > 1) {
        int now = n;
        while (del and now % 2 == 0)del--, now /= 2;
        (cur *= now) %= m;
        n--;
    }
    return cur;
}

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i], mp[v[i]]++;
    int ct = 0;
    for (int i = 0, tp; i < n; i++) {
        cin >> tp;
        if (tp == v[i])ct++;
        mp[tp]++;
    }
    cin >> m;
    int ans = 1;
    for (auto x: mp) (ans *= fact(x.second, ct)) %= m;
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