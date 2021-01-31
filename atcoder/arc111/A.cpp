#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int pw(int a, int b, int m) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1, m) % m;
    return pw(a * a % m, b / 2, m);
}

void solve() {
    int n, m;
    cin >> n >> m;

    int val = (pw(10, n, m * m) / m) % m;
    cout << val << endl;
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