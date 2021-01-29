#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int now = v[0], val = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] * 100 <= k * now) {
            now += v[i];
            continue;
        }
        val += (v[i] * 100 + k - 1) / k - now;
        now = (v[i] * 100 + k - 1) / k + v[i];
    }
    cout << val << endl;
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