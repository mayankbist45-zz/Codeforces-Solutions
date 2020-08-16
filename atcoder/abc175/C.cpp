#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    int tp = x / d;
    x -= min(tp, k) * d;
    k -= min(k, tp);

    if (k & 1)x -= d;
    cout << abs(x) << endl;
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