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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    multiset<int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = mp.upper_bound(-v[i]);
        if (x == mp.end()) {
            ans++;
            mp.insert(-v[i]);
        } else {
            mp.erase(x);
            mp.insert(-v[i]);
        }
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