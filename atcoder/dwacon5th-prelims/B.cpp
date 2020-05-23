#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> sum;
    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = i; j < n; j++) {
            sm += v[j];
            sum.push_back(sm);
        }
    }
    int ans = 0;
    for (int i = 60; i >= 0; i--) {
        int tp = ans | (1ll << i), ct = 0;
        for (auto x: sum) if ((x & tp) == tp)ct++;
        if (ct >= k)ans = tp;
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