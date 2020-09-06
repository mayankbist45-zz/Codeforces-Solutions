#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;

    cout << fixed << setprecision(10);
    if (a == 0 and b == 0)
        cout << 1.0 << endl;
    else if (b == 0)
        cout << 1.0 << endl;
    else if (a == 0)
        cout << 0.5 << endl;
    else {
        double ans = 0;
        int tp = b * 4;
        if (tp > a)ans = ((1.0 * a * b) + (a * 1.0 * a) / 8.0) / (a * b * 2);
        else ans = (2.0 * a * b - (1.0 * b * tp) / 2.0) / (a * b * 2);
        cout << ans << endl;
    }

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