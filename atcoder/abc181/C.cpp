#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

bool isCol(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return a.first * (b.second - c.second) +
           b.first * (c.second - a.second) +
           c.first * (a.second - b.second) == 0;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x: v)cin >> x.first >> x.second;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (isCol(v[i], v[j], v[k])) {
//                    debug(v[i], v[j], v[k])
                    cout << "Yes";
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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