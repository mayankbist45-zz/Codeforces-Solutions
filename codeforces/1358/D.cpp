#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int getSum(int a) {
    return a * (a + 1) / 2;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i], ans[i] = getSum(v[i]);
    for (int i = 1; i <= n; i++)v.push_back(v[i]);
    for (int i = 1; i <= n; i++)ans.push_back(ans[i]);
    partial_sum(v.begin(), v.end(), v.begin());
    partial_sum(ans.begin(), ans.end(), ans.begin());
    int mx = 0;
    for (int i = 1; i <= 2 * n; i++) {
        //this one is end of the day
        int curans = 0;
        if (v[i] < x)continue;
        //find the left end
        int lo = 1, hi = i, mid, lf = 0;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (v[i] - v[mid - 1] >= x) {
                lf = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        int need = x - (v[i] - v[lf]);
        curans = getSum(v[lf] - v[lf - 1]) - getSum(v[lf] - v[lf - 1] - need) + ans[i] - ans[lf];
        mx = max(mx, curans);
    }
    cout << mx << endl;
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