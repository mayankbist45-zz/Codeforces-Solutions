#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int ct = 0;

    while (n > 1) {
        if (n & 1)n--;
        else {
            int val = n / 2;
            n /= max(val, 2ll);
        }
        ct++;
    }
    cout << ct << endl;
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