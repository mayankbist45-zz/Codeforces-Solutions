#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

int pw[maxn + 10];

void solve() {
    int k;
    cin >> k;

    pw[0] = 1;
    pw[0] %= k;
    for (int i = 1; i <= maxn; i++)pw[i] = (pw[i - 1] * 10) % k;
    int cur = 0;
    for (int d = 1; d <= maxn; d++) {
        cur = (cur + pw[d - 1] * 7 % k);
        cur %= k;
        if (cur == 0) {
            cout << d << endl;
            return;
        }
    }
    cout << -1 << endl;
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