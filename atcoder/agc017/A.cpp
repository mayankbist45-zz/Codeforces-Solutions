#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

long long C(int n, int r) {
    if (r > n - r) r = n - r;
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> v(n);
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] & 1)o++;
        else e++;
    }
    int ans = 0;
    if (p == 1) {
        int tp = 0;
        for (int i = 1; i <= o; i += 2)
            tp += C(o, i);
        ans = pow(2, e) * (tp);
    } else {
        int tp = 0;
        for (int i = 0; i <= o; i += 2)
            tp += C(o, i);
        ans = pow(2, e) * (tp);
    }
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