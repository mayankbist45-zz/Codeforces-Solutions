#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 1;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (m / i >= n)
                ans = max(ans, i);
            if (i >= n)
                ans = max(ans, m / i);
        }
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