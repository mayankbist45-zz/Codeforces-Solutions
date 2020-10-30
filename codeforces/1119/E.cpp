#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int rem = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int got = min(v[i] - (v[i] & 1), 2 * rem);
        rem -= got / 2;
        ans += got / 2;

        v[i] -= got;
        ans += v[i] / 3;
        rem += v[i] % 3;
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