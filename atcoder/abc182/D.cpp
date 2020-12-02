#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());
    vector<int> b = v;
    for (int i = 1; i < v.size(); i++)b[i] = max(b[i], b[i - 1]);
    int mx = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, cur + b[i]);
        cur += v[i];
        mx = max(mx, cur);
    }
    cout << mx;
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