#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    map<string, int> mp;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, mp[v[i]]);
    }
    for (auto x: mp) {
        if (x.second == mx)
            cout << x.first << endl;
    }

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