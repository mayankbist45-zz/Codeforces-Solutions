#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int mx = 0;
    for(auto x: mp)mx = max(mx, x.second);
    cout << mx << endl;
    
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