#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


void compress(vector<int> &v) {
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

vector<vector<int>> dp, rg;

int solve(int l, int r) {
    if (l > r)return 0;
    int &ans = dp[l][r];
    if (ans != -1)return ans;
    ans = 0;
    int add = count(rg[l].begin(), rg[l].end(), r);
    ans = max(ans, add + solve(l + 1, r));
    for (auto x: rg[l]) if (x < r)ans = max(ans, add + solve(l, x) + solve(x + 1, r));
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> l(n), r(n), val;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        val.push_back(l[i]);
        val.push_back(r[i]);
    }
    compress(val);
    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
        r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin();
    }

    int sz = val.size();
    dp = vector<vector<int>>(sz, vector<int>(sz, -1));
    rg = vector<vector<int>>(sz);
    for (int i = 0; i < n; i++)rg[l[i]].push_back(r[i]);
    cout << solve(0, sz - 1) << endl;
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