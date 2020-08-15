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

    map<int, int> mp;
    mp[0]++;
    int ans = 0, pre = 0;
    for (int i = 0; i < n; i++) {
        pre += s[i] - '0';
        ans += mp[pre - i - 1];
        mp[pre - i - 1]++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}