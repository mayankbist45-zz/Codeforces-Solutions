#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n, 9);
    for (int i = v.size() - 1; i >= 0 and n > 0; i--) {
        v[i] = 8;
        n -= 4;
    }
    for (auto x: v)cout << x;
    cout << endl;
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