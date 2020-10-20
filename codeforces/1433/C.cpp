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
    if (count(v.begin(), v.end(), v.front()) == n) {
        cout << -1 << endl;
        return;
    }
    int mx = *max_element(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        bool fd = false;
        if (v[i] == mx) {
            if (i + 1 < n and v[i + 1] < v[i])fd = true;
            if (i - 1 >= 0 and v[i - 1] < v[i])fd = true;
            if (fd) {
                cout << i + 1 << endl;
                return;
            }
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