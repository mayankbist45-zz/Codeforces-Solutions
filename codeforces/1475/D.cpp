#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> one, two;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1)one.push_back(a[i]);
        else two.push_back(a[i]);
    }
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());

    partial_sum(one.begin(), one.end(), one.begin());
    partial_sum(two.begin(), two.end(), two.begin());

    int mn = LLONG_MAX;
    for (int sel = 0; sel <= one.size(); sel++) {
        int sum = 0;
        if (sel)sum += one[sel - 1];
        int need = m - sum;
        if (need <= 0) {
            mn = min(mn, sel);
            continue;
        }
        if (two.empty() or two.back() < need)continue;
        auto tp = lower_bound(two.begin(), two.end(), need) - two.begin();
        mn = min(mn, sel + 2 * (tp + 1));
    }
    if (mn == LLONG_MAX)mn = -1;
    cout << mn << endl;
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