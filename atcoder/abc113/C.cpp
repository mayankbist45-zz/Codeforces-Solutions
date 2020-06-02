#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

set<pair<int, int>> g[maxn];

string twelve(int a, int b) {
    string aa = to_string(a);
    string bb = to_string(b);
    int zero1 = 6 - aa.size(), zero2 = 6 - bb.size();
    return string(zero1, '0') + aa + string(zero2, '0') + bb;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert({b, i});
    }
    vector<string> ans(m);
    for (int i = 0; i < maxn; i++) {
        int id = 1;
        for (auto x: g[i]) {
            int p = i;
            ans[x.second] = twelve(p, id);
            id++;
        }
    }
    for (auto x: ans)cout << x << endl;
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