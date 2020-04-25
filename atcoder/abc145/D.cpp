#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

int fact[maxn];

int pw(int a, int b,int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}

int inverse(int a) {
    return pw(a, MOD - 2);
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = i * fact[i - 1] % MOD;
    int x, y;
    cin >> x >> y;

    int a = (2 * y - x) / 3;
    int b = (x - a) / 2;
    if (a < 0 or b < 0 or (x + y) % 3) {
        cout << 0;
        return;
    }
    int ans = fact[a + b] * (inverse(fact[a] * fact[b] % MOD)) % MOD;
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