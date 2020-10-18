#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;
    int val = 0;
    for (int i = 0; i < 32; i++) {
        if (((a >> i) & 1) and ((b >> i) & 1))val |= (1 << i);
    }
    int ans = (a ^ val) + (b ^ val);
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