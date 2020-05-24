#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct pot {
    int a, b, pt;
};

void solve() {
    int d, g;
    cin >> d >> g;

    vector<pot> v(d);
    vector<int> perm(d);
    iota(perm.begin(), perm.end(), 0);
    for (int i = 0; i < d; i++) {
        cin >> v[i].a >> v[i].b;
        v[i].pt = (i + 1) * 100;
    }

    int ct = LLONG_MAX;
    do {
        int pct = 0, ans = 0;
        for (int i = 0; i < d; i++) {
            int idx = perm[i];
            int need = g - ans;
            int del = need / v[idx].pt + (need % v[idx].pt > 0);

            if (del <= v[idx].a) {
                pct += del;
                ans += del * v[idx].pt;
            } else if (del > v[idx].a) {
                ans += v[idx].a * v[idx].pt;
                pct += v[idx].a;
            }
            if (del >= v[idx].a)ans += v[idx].b;
            if (ans >= g)break;
        }
        ct = min(ct, pct);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ct << endl;
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