#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    vector<int> suf(s.size() + 1);
    map<int, int> mp;
    suf.back() = (s.back() - '0');

    mp[0]++;
    mp[suf.back()]++;
    int init = 10;
    for (int i = s.size() - 1; i > 0; i--) {
        suf[i] = (suf[i + 1] + (s[i - 1] - '0') * init % 2019) % 2019;
        init *= 10;
        init %= 2019;
        mp[suf[i]]++;
    }
    int ans = 0;
    for (auto x: mp)
        ans += x.second * (x.second - 1) / 2;
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