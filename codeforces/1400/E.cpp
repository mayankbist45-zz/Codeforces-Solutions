#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int a[maxn];

int solve(int s, int e) {
    if (s > e)return 0;
    int minus = max(a[s - 1], a[e + 1]);
    int mn = min_element(a + s, a + e + 1) - a;
    int mnVal = a[mn];

    return min(e - s + 1, solve(s, mn - 1) + solve(mn + 1, e) + mnVal - minus);
}

void solve() {
    int n;;
    cin >> n;

    for (int i = 1; i <= n; i++)cin >> a[i];
    cout << solve(1, n) << endl;
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