#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, m, k;

int check(int mid) {
    int ct = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(m, (mid - 1) / i);
    }
    return ans < k;
}

void solve() {
    cin >> n >> m >> k;

    int lo = 1, hi = m * n, mid, ans;

    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
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