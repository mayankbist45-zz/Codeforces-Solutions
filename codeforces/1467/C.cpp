#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<vector<int>> v(3);
    v[0] = vector<int>(n1);
    v[1] = vector<int>(n2);
    v[2] = vector<int>(n3);
    for (int i = 0; i < n1; ++i)cin >> v[0][i];
    for (int i = 0; i < n2; ++i)cin >> v[1][i];
    for (int i = 0; i < n3; ++i)cin >> v[2][i];

    vector<int> sum = {accumulate(v[0].begin(), v[0].end(), 0ll),
                       accumulate(v[1].begin(), v[1].end(), 0ll),
                       accumulate(v[2].begin(), v[2].end(), 0ll)};

    for (auto &x: v)sort(x.begin(), x.end());
    int mx = LLONG_MIN;
    vector<int> perm = {0, 1, 2};
    do {
        vector<int> val = {sum[perm[0]] - v[perm[0]].front(),
                           v[perm[1]].front() - (sum[perm[2]] - v[perm[2]].front()),
                           v[perm[2]].front() - (sum[perm[1]] - v[perm[1]].front())};
        int now = max({sum[perm[0]] - val[1] - val[2], sum[perm[0]] - val[1] + val[2], sum[perm[0]] + val[1] - val[2]});
        mx = max(mx, now);
    } while (next_permutation(perm.begin(), perm.end()));
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