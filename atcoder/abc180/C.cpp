#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i)continue;
        div.push_back(i);
        if (n / i == i)continue;
        div.push_back(n / i);
    }
    sort(div.begin(), div.end(), [](auto &a, auto &b) {
        return a < b;
    });
    for(auto x: div)cout << x << endl;
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