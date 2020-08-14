#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;


int n;
bool check(int md, int k, int a, int b) {
    int ans = 0, mx = 0;
    if (k > a) {
        int tp = k - a;
        int time = tp / a + (tp % a > 0);
        mx = time;
    }

    if (mx < md)return false;
    ans += md;
    k -= a * md;
    int tp = k - b;
    int time = tp / b + (tp % b > 0);
    ans += time;
    k -= b * time;
    return ans >= n;
}

int k, a, b;

void solve() {
    cin >> k >> n >> a >> b;

    int lo = 0, hi = 1e9, mid, ans = -1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid, k, a, b)) {
            lo = mid + 1;
            ans = mid;
        } else hi = mid - 1;
    }
    cout << min(ans, n) << endl;
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