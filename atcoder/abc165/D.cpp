#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int a, b;
int n;

int f(double x) {
    return (int) (floor((a * x) / b) - a * floor(x / b));
}

void solve() {
    cin >> a >> b >> n;
    cout << f(min(n, b - 1)) << endl;
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