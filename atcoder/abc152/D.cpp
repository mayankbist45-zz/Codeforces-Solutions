#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

inline int stoii(string &s) {
    int ans = 0;
    for (auto x:s)ans = ans * 10 + x - '0';
    return ans;
}

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        mp[{s.front() - '0', s.back() - '0'}]++;
    }
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        swap(s.back(), s.front());
        int val = stoii(s);

        ans += mp[{s.front() - '0', s.back() - '0'}];
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