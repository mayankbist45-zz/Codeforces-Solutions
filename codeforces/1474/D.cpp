#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int ct = 0;
    vector<int> v(n + 2), pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] < pre[i - 1] or pre[i - 1] == -1)pre[i] = -1, ct++;
        else pre[i] = v[i] - pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (v[i] < suf[i + 1] or suf[i + 1] == -1)suf[i] = -1;
        else suf[i] = v[i] - suf[i + 1];
    }
    if (pre[n] == 0 and !ct) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (pre[i - 1] == -1 or suf[i + 2] == -1)continue;
        if (v[i + 1] < pre[i - 1])continue;
        if (v[i] < suf[i + 2])continue;
        if (v[i] - suf[i + 2] == v[i + 1] - pre[i - 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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