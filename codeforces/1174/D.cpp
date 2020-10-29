#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;

    if (x >= (1 << n)) {
        cout << (1 << n) - 1 << endl;
        for (int i = 1; i < (1 << n); i++) {
            cout << (i ^ (i - 1)) << " ";
        }
    } else {
        vector<bool> vis(1 << n);
        vector<pair<int, int>> v;
        vis[x] = 1;
        for (int i = 1; i < (1 << n); i++) {
            if (vis[i])continue;
            int nx = x ^i;
            vis[nx] = vis[i] = 1;
            v.push_back({i, nx});
        }
        int prev = 0;
        cout << v.size() << endl;
        for (auto x: v) {
            cout << (x.first ^ prev) << " ";
            prev = x.first;
        }
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