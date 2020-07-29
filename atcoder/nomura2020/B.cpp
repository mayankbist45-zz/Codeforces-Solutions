#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    for (auto &x: s)if (x == '?')x = 'D';
    int ans = 0;
    cout << s << endl;
//    for (int i = 0; i < s.size(); i++) {
//        if (i + 1 < s.size() and s.substr(i, 2) == "PD") {
//            ans++;
//        }
//        if (s[i] == 'D')ans++;
//    }
//    cout << ans << endl;
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