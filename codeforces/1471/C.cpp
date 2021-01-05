#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n), cost(m);
    for (int i = 0; i < n; ++i) cin >> v[i], v[i] -= 1;
    for (int i = 0; i < m; ++i) cin >> cost[i];

    deque<pair<int, int>> dq;
    for (int i = 0; i < cost.size(); i++) dq.push_back({cost[i], i});
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        return cost[a] > cost[b];
    });

    int sum = 0;
    for (auto x: v) {
        if (dq.empty()) {
            sum += cost[x];
            continue;
        }
        if (dq.front().second <= x and dq.front().first < cost[x]) {
            sum += dq.front().first;
            dq.pop_front();
        } else {
            sum += cost[x];
        }
    }
    cout << sum << endl;
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