#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    int sum = n;
    if (n % k == 0) {
        cout << 1 << endl;
        return;
    }
    int need = k - n % k;

    int val = need / n;
    int ex = need % n;
    cout << val + (ex > 0) + 1 << endl;
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