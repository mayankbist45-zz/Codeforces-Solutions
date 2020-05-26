#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k, c;
    cin >> n >> k >> c;

    string s;
    cin >> s;

    vector<int> pf, sf;
    int d = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o')pf.push_back(i + 1), d++, i += c;
        if (d == k + 1)break;
    }
//    for(auto x: pf)cout << x << endl;
    d = k;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'o')sf.push_back(i + 1), d--, i -= c;
        if (d == 0)break;
    }
//    for(auto x: sf)cout << x << endl;

    reverse(sf.begin(), sf.end());
    for (int i = 0; i < sf.size(); i++) {
        if (sf[i] == pf[i])cout << sf[i] << endl;
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