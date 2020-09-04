#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;
    for (int d = 1; d <= 49; d++) {
        if ((y - x) % d != 0)continue;
        vector<int> v;
        int cur = y;
        while (cur > 0 and v.size() < n)v.push_back(cur), cur -= d;
        cur = y + d;
        while (v.size() < n)v.push_back(cur), cur += d;
        sort(v.begin(), v.end());
        if (v.size() == n and binary_search(v.begin(), v.end(), x) and binary_search(v.begin(), v.end(), y)) {
            for (auto x: v)cout << x << " ";
            cout << endl;
            return;
        }
    }
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