#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int get(int val, int cuts) {
    int len = val / cuts;
    int mod = val % cuts;
    return len * len * (cuts - mod) + (len + 1) * (len + 1) * mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    priority_queue<pair<int, pair<int, int>>> pq;
    int ans = 0;
    for (int i = 0; i < n; ++i) cin >> v[i], pq.push({get(v[i], 1) - get(v[i], 2), {v[i], 2}}), ans += v[i] * v[i];
    for (int i = 0; i < k - n; i++) {
        auto tp = pq.top();
        pq.pop();
        ans -= tp.first;
        pq.push({get(tp.second.first, tp.second.second) - get(tp.second.first, tp.second.second + 1),
                 {tp.second.first, tp.second.second + 1}});
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