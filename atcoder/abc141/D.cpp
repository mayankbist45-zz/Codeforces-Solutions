#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    priority_queue<int> pq;
    for (int tp, i = 0; i < n; ++i) {
        cin >> tp;
        pq.push(tp);
    }
    for (int i = 0; i < m; i++) {
        int tp = pq.top();
        pq.pop();
        pq.push(tp / 2);
    }
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
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