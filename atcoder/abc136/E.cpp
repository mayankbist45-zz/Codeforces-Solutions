#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, k;

bool valid(vector<int> &r, int d) {
    int tot = accumulate(r.begin(), r.end(), 0ll);

    if (tot == 0)return true;
    int maxK = 0, netR = 0;
    for (auto x: r) {
        maxK += d - x;
        netR += x;
        if (maxK == tot - netR and maxK <= k)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;

    int s = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i], s += v[i];

    vector<int> div;
    for (int i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            div.push_back(i);
            if (s / i != i)div.push_back(s / i);
        }
    }
    sort(div.rbegin(), div.rend());
    for (auto x: div) {
        vector<int> r;
        for (auto ele: v)r.push_back(ele % x);
        sort(r.rbegin(), r.rend());

        if (valid(r, x)) {
            cout << x << endl;
            return;
        }
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