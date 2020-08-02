#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, d;
    cin >> n >> d;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        double x = sqrt(a * a + b * b);
        if (x <= d)ans++;
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