#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> dp(n + 1 , 1);

    map<int, int> div;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        for (int j = 1; j * j <= v[i]; j++) {
            if (v[i] % j == 0) {
                if (div.count(j) and j != 1)
                    dp[i] = max(dp[i], 1 + dp[div[j]]);
                div[j] = i;
                if (v[i] / j != j)
                    if (div.count(v[i] / j))
                        dp[i] = max(dp[i], 1 + dp[div[v[i] / j]]);
                div[v[i] / j] = i;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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