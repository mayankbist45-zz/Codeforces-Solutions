#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    priority_queue<int> pq;
    int cur = 0;
    for (auto x: s) {
        if (x == '1')cur++;
        else {
            pq.push(cur);
            cur = 0;
        }
    }
    if (cur)pq.push(cur);
    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
        if (!pq.empty())pq.pop();
    }
    cout << ans << endl;
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