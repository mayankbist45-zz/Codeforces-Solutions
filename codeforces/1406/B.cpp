#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a, b;
    for (int i = 0, tp; i < n; ++i) {
        cin >> tp;
        if (tp >= 0)a.push_back(tp);
        else b.push_back(tp);
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
 
    int ans = LLONG_MIN;
    for (int i = 0; i <= 5; i++) {
        if(a.size() < i)continue;
        int need = 5 - i;
        if (need > b.size())continue;
 
        int cur = 1;
        for (int id = 0; id < i; id++)cur *= a[id];
        for (int id = 0; id < need; id++)cur *= b[id];
        ans = max(ans, cur);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i <= 5; i++) {
        if(a.size() < i)continue;
        int need = 5 - i;
        if (need > b.size())continue;
 
        int cur = 1;
        for (int id = 0; id < i; id++)cur *= a[id];
        for (int id = 0; id < need; id++)cur *= b[id];
        ans = max(ans, cur);
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