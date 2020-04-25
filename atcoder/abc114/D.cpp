#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 110
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = n; i > 0; i--) {
        int cur = i;
        for (int j = 2; j <= i; j++) {
            while (cur % j == 0)
                mp[j]++, cur /= j;
        }
    }

    map<int, int> cnt;
    for (auto x: mp) {
        if (x.second >= 74)cnt[74]++;
        if (x.second >= 14)cnt[14]++;
        if (x.second >= 4)cnt[4]++;
        if (x.second >= 24)cnt[24]++;
        if (x.second >= 2)cnt[2]++;
    }
    int ans = 0;
    //5 5 3
    ans = cnt[4] * (cnt[4] - 1) * (cnt[2] - 2) / 2;
    // 15 5
    ans += (cnt[4] - 1) * cnt[14];
    // 75
    ans += cnt[74];
    // 25 3
    ans += (cnt[2] - 1) * cnt[24];
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