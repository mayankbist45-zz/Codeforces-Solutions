#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
/*
 * choose k/2 elements at a min diffrence between elements
 * index of 2.
 * How to do that?
 * how about binary searching the k/2 elements
 */

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    int lo = 1, hi = 1e9, mid, ans;

    auto check = [&](int val) -> bool {
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= val) {
                ct++;
                i++;
                if (i < n)ct++;
            }
        }
        if (ct >= k)return true;
        ct = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] <= val) {
                ct++;
                i++;
                if (i < n)ct++;
            }
        }
        return ct >= k;
    };
    check(2);
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