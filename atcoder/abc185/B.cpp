#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    int pre = 0, bat = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        bat -= a - pre;
        if (bat <= 0) {
            cout << "No";
            return;
        }
        bat += b - a;
        bat = min(n, bat);
        pre = b;
    }
    bat -= t - pre;
    if (bat <= 0) {
        cout << "No";
        return;
    }
    cout << "Yes";
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