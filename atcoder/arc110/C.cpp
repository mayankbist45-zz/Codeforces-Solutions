#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
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
    int n;
    cin >> n;

    vector<int> v(n), inv(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    fenwick fw(n + 1);
    int ct = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        inv[i] = fw.sum(v[i], n);
        fw.add(v[i], 1);
        ct += inv[i];
        mp[v[i]] = i;
    }
    if (ct != n - 1) {
        cout << -1;
        return;
    }

    vector<int> ans;
    set<int> now;
    for (int i = 0; i < n; i++) {
        int pos = mp[i + 1];
        if (pos == i)continue;
        for (int j = pos; j >= i + 1; j--) {
            swap(v[j], v[j - 1]), ans.push_back(j);
            if (now.count(j)) {
                cout << -1;
                return;
            }
            now.insert(j);
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