#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

bool perfect(int val) {
    int now = sqrt(val);
    return now * now == val;
}

int sum(int st, int range) {
    return range * (2 * st + (range - 1)) / 2;
}

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int len = 1; len <= 2000000; len++) {
        int lo = 1, hi = n, mid;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (sum(mid, len) == n) {
                ans += 2;
                break;
            } else if (sum(mid, len) < n)lo = mid + 1;
            else hi = mid - 1;
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