#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m), v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> p[i];

    sort(p.begin(), p.end());
    for (int i = 0; i < m; i++) {
        int id = i;
        while (id + 1 < m and p[id + 1] == p[id] + 1)id++;
        sort(v.begin() + p[i] - 1, v.begin() + p[id] + 1);
        i = id;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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