#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int get(int a, int pos) {
    int rep = (1ll << (pos + 1));
    int val = (a + 1) / rep * (rep / 2);
    int dd = (a + 1) % rep;

    dd = max(0ll, dd - rep / 2);
    return val + dd;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i <= 60; i++) {
        int ct = (get(b, i) - get(a - 1, i)) % 2;
        if (ct)ans |= (1ll << i);
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