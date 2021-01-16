#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long
#define maxn 200010
const int MOD = 1000000007;

vector<int> getDivisors(int val) {
    vector<int> ret;
    for (int i = 1; i * i <= val; i++) {
        if (val % i)continue;
        if (i != 1)
            ret.push_back(i);
        if (val / i == i)continue;
        ret.push_back(val / i);
    }
    return ret;
}

vector<int> getPrimeFactors(int val) {
    vector<int> ret;
    for (int i = 2; i * i <= val; i++) {
        int cnt = 0;
        while (val % i == 0)cnt++, val /= i;
        if (cnt)ret.push_back(i);
    }
    if (val > 1)ret.push_back(val);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    vector<int> div = getPrimeFactors(accumulate(v.begin(), v.end(), 0ll));
    int mn = LLONG_MAX;
    vector<int> pre = v;
    partial_sum(pre.begin(), pre.end(), pre.begin());
    for (auto x: div) {
        int steps = 0;
        for (int i = 1; i <= n; i++) {
            steps += min(pre[i] % x, x - pre[i] % x);
        }
        mn = min(mn, steps);
    }
    if (mn == LLONG_MAX)mn = -1;
    cout << mn << endl;
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