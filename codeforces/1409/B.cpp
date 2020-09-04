#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


int solve(int a, int x, int b, int y, int n) {
    int na = max(x, a - n);
    n -= a - na;
    b = max(y, b - n);
    return na * b;
}

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int n;
    cin >> n;

    cout << min(solve(a, x, b, y, n), solve(b, y, a, x, n)) << endl;
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