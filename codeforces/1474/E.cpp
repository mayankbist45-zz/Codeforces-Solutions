#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);

    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        ans += (n - i) * (n - i) * ((i == 1) ? 1 : 2);
    }
    if (n & 1)ans += (n - (n + 1) / 2) * (n - (n + 1) / 2);
    cout << ans << endl;

    swap(perm.front(), perm.back());
    for (int i = 2; i <= (n + 1) / 2; i++) {
        if (n & 1 and i == (n + 1) / 2) {
            swap(perm[i - 1], perm.front());
            break;
        }
        swap(perm[i - 1], perm.back());
        swap(perm[n - i], perm.front());
    }
    for (auto x: perm)cout << x << " ";
    cout << endl;

    cout << n - 1 << endl;
    for (int i = (n + 1) / 2; i >= 1; i--) {
        if (n & 1 and i == (n + 1) / 2) {
            cout << (n + 1) / 2 << " " << 1 << endl;
            continue;
        }
        if (i == 1) {
            cout << 1 << " " << n << endl;
            continue;
        }
        cout << i << " " << n << endl;
        cout << n - i + 1 << " " << 1 << endl;
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