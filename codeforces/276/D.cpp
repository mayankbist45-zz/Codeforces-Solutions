#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int l, r;
    cin >> l >> r;
    int start = 1, ans = 0, ct = 0;
    while (start <= r - l) {
        ans += start;
        start *= 2;
        ct++;
    }
    while (start <= r) {
        if ((((l >> ct) ^ (r >> ct)) & 1) == 1)ans += start;
        start *= 2;
        ct++;
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