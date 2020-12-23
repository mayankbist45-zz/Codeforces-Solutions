#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int solve(int val, vector<int> &a) {
    int ans = 0;
    for (auto x: a)ans += (x ^ val);
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> vis(60);
    for (int bit = 58; bit >= 0; bit--) {
        for (auto x: v) {
            if (x >> bit & 1)
                vis[bit]++;
        }
    }
//    for(auto x: vis)cout << x << " ";
//    cout << endl;
    int ans = 0;
    for (int bit = 58; bit >= 0; bit--) {
        if (vis[bit] + vis[bit] < n and (1ll << bit) + ans <= k) {
            ans += (1ll << bit);
        }
    }
//    cout << ans << endl;
    cout << max(solve(0, v), solve(ans, v)) << endl;
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