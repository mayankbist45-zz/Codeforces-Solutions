#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0, tp; i < n; ++i) {
        cin >> tp;
        dq.push_back(tp);
    }
    int par = 1, ct = 0;
    dq.pop_front();
    while (!dq.empty()) {
        int layer = 0;
        for (int i = 0; i < par; i++) {
            int prev = -1;
            while (!dq.empty() and (dq.front() > prev or prev == -1)) {
                prev = dq.front();
                dq.pop_front();
                layer++;
            }
        }
        ct++;
        par = layer;
    }
    cout << ct << endl;
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