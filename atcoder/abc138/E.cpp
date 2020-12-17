#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> v[26];
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a'].push_back(i);
    }
    int time = 0, pre = -1;
    for (auto x: t) {
        if (v[x - 'a'].empty()) {
            cout << -1 << endl;
            return;
        }
        auto tp = lower_bound(v[x - 'a'].begin(), v[x - 'a'].end(), pre + 1);
        if (tp == v[x - 'a'].end())time++, pre = v[x - 'a'].front();
        else pre = *tp;
    }
    cout << time * s.size() + pre + 1;
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
