#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, h;
    cin >> n >> h;

    vector<int> v;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        mx = max(mx, a);
        v.push_back(b);
    }
    sort(v.rbegin(), v.rend());
    int ct = 0;
    for (auto x: v) {
        if (h <= 0)break;
        if (mx >= x)break;
        ct++;
        h -= x;
    }
    if (h > 0)
        ct += h / mx + (h % mx > 0);
    cout << ct << endl;
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