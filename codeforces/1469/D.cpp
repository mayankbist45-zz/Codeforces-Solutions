#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    // 1, 2, 3, 4, 5, ..... , i- 1, i , i + 1 , ...  , n - 2, n - 1, n
    // min 3 elements

    // x ^ 6 = 2e5
    // n + 5 - n + 3 + 1 = 9
    // reduce 8 in 3

    vector<pair<int, int>> ans;
    for (int i = 3; i < n; i++) {
        if (i == 8)continue;
        ans.push_back({i, n});
    }
    int val = n;
    if (n <= 8) {
        while (val > 1) {
            ans.push_back({n, 2});
            val = (val + 1) / 2;
        }
    } else {
        while (val > 1) {
            ans.push_back({n, 8});
            val = (val + 7) / 8;
        }
        ans.push_back({8, 2});
        ans.push_back({8, 2});
        ans.push_back({8, 2});
    }
    cout << ans.size() << endl;
    for (auto x: ans)cout << x.first << " " << x.second << endl;
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