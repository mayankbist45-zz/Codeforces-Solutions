#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int destroy(int &mons, int &hp) {
    int mn = min(mons, hp);
    mons -= mn;
    hp -= mn;
    return mn;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 2), b(n + 1);
    for (int i = 0; i < n + 1; i++)cin >> v[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += destroy(v[i + 1], b[i]);
        ans += destroy(v[i], b[i]);
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