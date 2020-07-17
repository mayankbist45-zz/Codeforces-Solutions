#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(k, 2);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j] > i)continue;
            if (dp[i - v[j]] == 2)dp[i] = 1;
        }
    }
    cout << (dp[k] == 1 ? "First" : "Second") << endl;
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