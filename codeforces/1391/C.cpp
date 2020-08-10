#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
int pw(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}
 
void solve() {
    int n;
    cin >> n;
 
    int tp = pw(2, n - 1) + 2;
    if (tp >= 2)tp -= 2;
    int ans = 1;
    for (int i = 2; i <= n; i++)(ans *= i) %= MOD;
    int p = (ans - tp + MOD) % MOD;
    cout << p << endl;
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