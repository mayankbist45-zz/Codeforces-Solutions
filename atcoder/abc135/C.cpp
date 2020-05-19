#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1), h(n);
    for (int i = 0; i < n + 1; ++i) {
        cin >> v[i];
    }
    int ans = accumulate(v.begin(), v.end(), 0ll);
    for (int i = 0; i < n; i++) {
        cin >> h[i];

        if (h[i] >= v[i]) {
            h[i] -= v[i];
            v[i] = 0;
        } else {
            v[i] = v[i] - h[i];
            h[i] = 0;
        }

        if (h[i] >= v[i + 1]) {
            h[i] -= v[i + 1];
            v[i + 1] = 0;
        } else {
            v[i + 1] = v[i + 1] - h[i];
            h[i] = 0;
        }
    }
    cout << ans - accumulate(v.begin(), v.end(), 0ll) << endl;
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