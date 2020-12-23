#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

string a, b;
int n;

void solve() {
    cin >> n >> a >> b;
    int ans = 1, pre = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (pre == -1)
                ans *= 3;
            else if (pre == 1) {
                ans *= 2;
            }
            pre = 1;
        } else {
            if (pre == -1)ans *= 6;
            else if (pre == 1)ans *= 2;
            else ans *= 3;

            pre = 2;
            i++;
        }
        ans %= MOD;
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