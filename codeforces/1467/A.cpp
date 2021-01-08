#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 9 << endl;
        return;
    } else if (n == 2) {
        cout << 98 << endl;
        return;
    }

    int val = 9;
    cout << 989;
    n -= 3;
    for (int i = 0; i < n; i++) {
        cout << i % 10;
    }
    cout << endl;
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