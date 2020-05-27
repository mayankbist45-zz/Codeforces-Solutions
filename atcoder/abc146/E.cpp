#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i] + v[i] - 1) % k;
    }
    int ans = 0;
    map<int, int> mp;
    mp[0]++;
    for (int i = 0, j = 1; j <= n; j++) {
        if (j - i == k) {
            mp[pre[i++]]--;
        }
        ans = (ans + mp[pre[j]]);
        mp[pre[j]]++;
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