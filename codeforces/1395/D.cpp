#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> v1, v2;

void solve() {
    int n, d, m;
    cin >> n >> d >> m;
    for (int i = 0, tp; i < n; ++i) {
        cin >> tp;
        if (tp <= m)v1.push_back(tp);
        else v2.push_back(tp);
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());

    partial_sum(v1.begin(), v1.end(), v1.begin());
    partial_sum(v2.begin(), v2.end(), v2.begin());

    int rg = n, ans = 0;
    if (!v1.empty())ans += v1.back();
    if (!v2.empty())ans += v2.front();

    for (int i = 1; i <= v2.size(); i++) {
        int mn = i, pre = 0;
        if ((mn - 1) * d + mn > n)continue;
        if (mn <= v2.size()) pre += v2[mn - 1];
        int need = n - ((mn - 1) * d + mn);
        need = min(need, (int) v1.size());
        if (need - 1 >= 0)
            pre += v1[need - 1];
        ans = max(ans, pre);
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