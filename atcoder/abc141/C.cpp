#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        v[0]--, v[a]++;
        if (a + 1 <= n)v[a + 1]--;
    }
    partial_sum(v.begin(), v.end(), v.begin());
    for (int i = 1; i <= n; i++) {
        auto x = v[i];
        if (x + k <= 0)cout << "No";
        else cout << "Yes";
        cout << endl;
    }
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