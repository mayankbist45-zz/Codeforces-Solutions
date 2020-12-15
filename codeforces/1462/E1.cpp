#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010

long long C(int n, int r) {
    if(n < r)return 0;
    if(r > n - r) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void solve() {
    int n, m = 3, k = 2;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int pre = 0, ed = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, mid, cur = i;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (v[mid] - v[i] <= k) {
                lo = mid + 1;
                cur = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (cur <= ed)continue;
        if (i > ed) {
            ans += C(cur - i + 1, m);
        } else {
            for (int time = 0; time < m; time++) {
                ans += C(ed - i + 1, time) * C(cur - ed, m - time);
            }
        }
        ed = cur;
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