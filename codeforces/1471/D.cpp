#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> mp, tp, vis;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (vis.count(v[i])) {
            v[i] = vis[v[i]];
        } else {
            int now = 1, temp = v[i];
            for (int div = 2; div * div <= v[i]; div++) {
                int ct = 0;
                while (v[i] % div == 0) {
                    v[i] /= div;
                    ct++;
                }
                if (ct & 1)now *= div;
            }
            if (v[i] > 1)now *= v[i];
            vis[temp] = now;
            v[i] = now;
        }
        mp[v[i]]++;
    }
    tp = mp;
    int a1 = 0, a2 = 0;
    for (auto &x: mp) {
        a1 = max(a1, x.second);
        if (x.first > 1 and x.second % 2 == 0) {
            tp[1] += x.second;
            tp[x.first] = 0;
        }
    }
    for (auto x: tp)a2 = max(a2, x.second);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int w;
        cin >> w;
        cout << (w == 0 ? a1 : a2) << endl;
    }
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