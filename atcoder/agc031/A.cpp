#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> mp;
    for (auto x: s)
        mp[x]++;
    int ans = 1;
    for (auto x: mp) {
        ans *= (x.second + 1);
        ans %= MOD;
    }
    cout << (ans - 1 + MOD) % MOD << endl;
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