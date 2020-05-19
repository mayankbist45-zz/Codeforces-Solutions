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
    int mx = 0, cur = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1])cur++;
        else mx = max(mx, cur), cur = 0;
    }
    mx = max(mx, cur), cur = 0;
    cout << mx << endl;
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