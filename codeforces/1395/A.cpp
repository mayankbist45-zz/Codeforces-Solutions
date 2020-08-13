#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int r, g, b, w;
    cin >> r >> g >> b >> w;

    int cnt = r % 2 + g % 2 + b % 2 + w % 2;
    if (cnt <= 1)cout << "Yes" << endl;
    else if (r and g and b) {
        r--, g--, b--;
        w += 3;
        cnt = r % 2 + g % 2 + b % 2 + w % 2;
        if (cnt <= 1)cout << "Yes" << endl;
        else cout << "No" << endl;
    } else
        cout << "No" << endl;
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