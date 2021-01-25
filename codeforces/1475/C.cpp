#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> boy(k), girl(k);
    vector<int> cnta(a + 1), cntb(b + 1);
    for (int i = 0; i < k; ++i) {
        cin >> boy[i];
        cnta[boy[i]]++;
    }
    for (int i = 0; i < k; ++i) {
        cin >> girl[i];
        cntb[girl[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += (k - i -1) - (cnta[boy[i]] - 1) - (cntb[girl[i]] - 1);
        cnta[boy[i]]--;
        cntb[girl[i]]--;
    }
    cout << ans << endl;
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