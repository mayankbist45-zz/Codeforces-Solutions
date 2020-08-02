#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int v[maxn];
int n;
int k;

bool check(int m) {
    int times = 0;
    for (int i = 0; i < n; i++) {
        times += v[i] / m + (v[i] % m > 0) - 1;
    }
    return times <= k;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> v[i];
    int lo = 1, hi = 1e12, mid, ans = 0;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
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