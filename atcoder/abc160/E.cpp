#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> red(a), green(b), col(c);
    for (int i = 0; i < a; i++)cin >> red[i];
    for (int i = 0; i < b; i++)cin >> green[i];
    for (int i = 0; i < c; i++)cin >> col[i];
    sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());
    sort(col.rbegin(), col.rend());

    red.resize(x);
    green.resize(y);

    vector<int> cal;

    for (auto &xx: red)cal.push_back(xx);
    for (auto &xx: green)cal.push_back(xx);
    for (auto &xx: col)cal.push_back(xx);

    sort(cal.rbegin(), cal.rend());
    cout << accumulate(cal.begin(), cal.begin() + x + y, 0ll);
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