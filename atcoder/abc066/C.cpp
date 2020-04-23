#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int o = 1;
    deque<int> d;
    for (int i = 0; i < n; i++) {
        if (o)
            d.push_back(v[i]);
        else
            d.push_front(v[i]);
        o ^= 1;
    }
    if(o == 0)
        reverse(d.begin(), d.end());
    for(auto x: d)cout << x << " ";
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