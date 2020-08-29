#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string a, b;
    cin >> a >> b;

    int ans = 10000;
    for (int i = 0; i + b.size() <= a.size(); i++) {
        int cur = 0;
        for (int j = i; j < i + b.size(); j++) {
            cur += a[j] != b[j - i];
        }
        ans = min(ans, cur);
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
