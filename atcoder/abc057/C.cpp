#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int st(int a, int b) {
    return max(to_string(a).size(), to_string(b).size());
}

void solve() {
    int n;
    cin >> n;
    int ans = LLONG_MAX;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i, b = n / i;
            ans = min(ans, st(a, b));
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