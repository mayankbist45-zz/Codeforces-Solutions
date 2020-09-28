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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int a = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == k / 2 and k % 2 == 0)cout << a << " ", a ^= 1;
        else if (v[i] <= k / 2)cout << 0 << " ";
        else cout << 1 << " ";
    }
    cout << endl;;
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