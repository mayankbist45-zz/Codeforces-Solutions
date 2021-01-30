#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

struct fenwick {
    int n;
    vector<int> bit;

    fenwick(int _n) : bit(_n), n(_n) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += val;
    }

    int pref(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & (-idx))
            ans += bit[idx];
        return ans;
    }

    int sum(int a, int b) { return pref(b) - pref(a - 1); }
};


void solve() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<pair<int, int>> v(n);
//    for (auto &x: v)cin >> x.first >> x.second;
//
    int n;
    cin >> n;

    vector<int> v(n);
    fenwick fw(n + 1);
    int inv = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        inv += fw.sum(v[i] + 1, n);
        fw.add(v[i] + 1, 1);
    }
    cout << inv << endl;
    vector<int> ans;
    for (int i = n - 1; i > 0; i--) {
        int low = v[i];
        int hi = n - 1 - v[i];

        inv -= hi;
        inv += low;

        ans.push_back(inv);
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans)cout << x << endl;
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