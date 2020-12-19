#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int r = 0, bl = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            r++;
        } else if (a[i] < b[i]) {
            bl++;
        }
    }
    if (r > bl)cout << "RED";
    else if (bl > r)cout << "BLUE";
    else cout << "EQUAL";
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