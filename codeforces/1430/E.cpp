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
    string s;
    cin >> s;
    string b = s;
    reverse(b.begin(), b.end());
    vector<int> g[26];
    for (int i = b.size() - 1; i >= 0; i--)g[b[i] - 'a'].push_back(i);
    vector<int> id;
    for (int i = 0; i < s.size(); i++) {
        id.push_back(g[s[i] - 'a'].back());
        g[s[i] - 'a'].pop_back();
    }
    fenwick bit(n + 10);
    int ans = 0;
    for (auto &x: id) {
        ans += bit.sum(x + 1, n);
        bit.add(x + 1, 1);
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