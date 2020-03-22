#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

long long C(int n, int r) {
    if (n < r)
        return 0;
    if (r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int ans = 0;
    for (auto x: mp)
        ans += C(x.second, 2);
    for (int i = 0; i < n; i++) {
        int pans = ans - C(mp[v[i]], 2);
        pans += C(mp[v[i]] - 1, 2);
        cout << pans << endl;
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