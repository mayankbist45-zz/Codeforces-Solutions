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
    for (int i = 0; i < n; ++i) cin >> v[i];
    int sum = accumulate(v.begin(), v.end(), 0ll);
    for (int i = 0; i <= n; i++) {
        int seg = n - i;
        if (sum % seg)continue;
        bool fl = true;
        int val = 0;
        for (int j = 0; j < n; j++) {
            val += v[j];
            if (val == sum / seg)val = 0;
            else if (val > sum / seg) {
                fl = false;
                break;
            }
        }
        if (fl) {
            cout << i << endl;
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