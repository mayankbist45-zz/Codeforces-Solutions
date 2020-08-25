#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int x;
    cin >> x;

    string ans(s.size(), '1');
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i + x < s.size())ans[i + x] = '0';
            if (i - x >= 0)ans[i - x] = '0';
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (i + x < s.size() and ans[i + x] == '1' and s[i] == '1')continue;
        if (i - x >= 0 and ans[i - x] == '1' and s[i] == '1')continue;
        else if (s[i] == '0')continue;

        cout << -1 << endl;
        return;
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