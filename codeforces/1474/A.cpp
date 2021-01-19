#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans(n, '0');
    int pre = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (pre != 2)ans[i] = '1', pre = 2;
            else ans[i] = '0', pre = 1;
        } else {
            if (pre != 1)ans[i] = '1', pre = 1;
            else ans[i] = '0', pre = 0;
        }
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