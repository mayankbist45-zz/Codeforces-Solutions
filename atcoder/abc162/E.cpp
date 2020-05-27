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
    int n, k;
    cin >> n >> k;

    vector<int> ans(k + 1);
    int pans = 0;
    for (int i = k; i >= 1; i--) {
        ans[i] = pw(k / i, n);
        for (int j = 2; j * i <= k; j++) {
            ans[i] = (ans[i] - ans[i * j] + MOD) % MOD;
        }
        pans = (pans + ans[i] * i % MOD) % MOD;
    }
    cout << pans << endl;
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