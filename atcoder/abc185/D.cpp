#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for (int i = 1; i <= m; ++i) {
        cin >> v[i - 1];
    }
    sort(v.begin(), v.end());
    int pre = 0, ans = INT_MAX, ct = 0;
    vector<int> val;
    for (auto x:v) {
        if (x - pre - 1 > 0)
            ans = min(ans, x - pre - 1);
        val.push_back(x - pre - 1);
        pre = x;
    }
    if (n > pre)
        ans = min(ans, n - pre), val.push_back(n - pre);
    for (auto x:val) {
        ct += x / ans + (x % ans > 0);
    }
    cout << ct << endl;
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