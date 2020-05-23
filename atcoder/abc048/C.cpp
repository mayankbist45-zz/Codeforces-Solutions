#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int x;
    cin >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] + v[i - 1] > x) {
            int need = (v[i] + v[i - 1]) - x;
            ans += need;
            if (need <= v[i])
                v[i] -= need, need = 0;
            else v[i - 1] -= (need - v[i]), v[i] = 0;
        }
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