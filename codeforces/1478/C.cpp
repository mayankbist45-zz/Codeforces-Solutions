#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    n *= 2;
    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto x: mp) {
        if (x.second != 2) {
            cout << "NO" << endl;
            return;
        }
    }
    sort(v.rbegin(), v.rend());

    int sum = 0, id = n / 2;
    for (int i = 0; i < n; i += 2) {
        int val = v[i] - sum;
        if (val % (2 * id) != 0) {
            cout << "NO" << endl;
            return;
        }
        if (val / id <= 0) {
            cout << "NO" << endl;
            return;
        }
        sum += val / id;
        id--;
    }
    cout << "YES" << endl;
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