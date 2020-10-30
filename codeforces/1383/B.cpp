#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int bit = 31; bit >= 0; bit--) {
        int ct = 0;
        for (auto x: v)if (x >> bit & 1)ct++;
        if (ct % 2 == 0)continue;
        if (ct % 4 == 3 and (n - ct) % 2 == 0)cout << "LOSE" << endl;
        else cout << "WIN" << endl;
        return;
    }
    cout << "DRAW" << endl;
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