#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    vector<int> mp(110);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        mp[log2(v[i])]++;
    }
    sort(v.begin(), v.end());
    if (accumulate(v.begin(), v.end(), 0ll) < n) {
        cout << -1 << endl;
        return;
    }
    for (auto &x: v)x = log2(x);
    int ct = 0;
    for (int i = 0; i < 62;) {
        if ((n >> i) & 1) {
            if (mp[i])mp[i]--;
            else {
                while (i < 62 and !mp[i])i++, ct++;
                mp[i]--;
                continue;
            }
        }
        mp[i + 1] += mp[i] / 2;
        i++;
    }
    cout << ct << endl;
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