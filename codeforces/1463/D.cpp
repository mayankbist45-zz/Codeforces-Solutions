#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (binary_search(v.begin(), v.end(), i + 1))continue;
        b.push_back(i + 1);
    }
    vector<int> ct(n + 1);
    ct[0] = ct[n] = 1;
    int lo = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto x = v[i];
        while (lo < n and b[lo] < x)lo++;
        if (lo < n)ct[++ans]++, lo++;
    }
    lo = n - 1, ans = n;
    for (int i = n - 1; i >= 0; i--) {
        auto x = v[i];
        while (lo > -1 and b[lo] > x)lo--;
        if (lo > -1)ct[--ans]++, lo--;
    }
    int val = 0;
    for (int i = 0; i <= n; i++)val += ct[i] == 2;
    cout << val << endl;
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