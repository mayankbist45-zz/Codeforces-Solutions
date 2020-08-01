#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
int n;

void solve() {
    cin >> n;
    vector<int> v(n), c;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i += 2)c.push_back(v[i]);
    for (int i = 1; i < n; i += 2)c.push_back(v[i]);
    for (int i = 0; i < n; i += 2)c.push_back(v[i]);
    for (int i = 1; i < n; i += 2)c.push_back(v[i]);

    int tp = (n + 1) / 2;
    int cur = 0, mx = 0;
    for (int i = 0; i < tp; i++)cur += c[i];
    mx = max(mx, cur);
    for (int i = tp, j = 0; i < c.size(); i++, j++)cur -= c[j], cur += c[i], mx = max(mx, cur);
    cout << mx << endl;
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