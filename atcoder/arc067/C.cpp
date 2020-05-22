#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int ii = i;
        for (int j = 2; j * j <= ii; j++) {
            while (ii % j == 0) {
                ii /= j;
                mp[j]++;
            }
        }
        if(ii > 1)mp[ii]++;
    }
    int ans = 1;
    for (auto x: mp) {
        ans = (ans * (x.second + 1)) % MOD;
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