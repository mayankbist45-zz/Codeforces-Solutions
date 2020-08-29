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

int inverse(int a) {
    return pw(a, MOD - 2);
}


void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    int sum = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        sum2 += (v[i] * v[i]) % MOD;
        sum2 %= MOD;
    }
    sum %= MOD;
    sum = (sum * sum) % MOD;
    sum = (sum - sum2 + MOD) % MOD;
    sum *= inverse(2);
    sum %= MOD;
    cout << sum << endl;
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