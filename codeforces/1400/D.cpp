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
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        map<int, int> tp;
        int cur = 0;
        for (int j = i + 1; j < n; j++) {
            if (v[j] == v[i])ans += cur;
            tp[v[j]]++;
            if (mp.count(v[j]))cur += mp[v[j]];
        }
        mp[v[i]]++;
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