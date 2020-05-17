#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
#define PI acos(-1)

void solve() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    long double ha = h * 30 + m * 0.5;
    // cout << PI << endl;
    const double halfC = PI / 180;
    long double hm = m * 6;

//    cout << ha << " " << hm << endl;

    long double hh = abs(ha - hm);
    if (hh > 360 - hh)
        hh = 360 - hh;
//    cout << hh << endl;
    hh *= halfC;
    // cout << ha << " " << hm << endl;

//    cout << hh << endl;
    long double ans = b * b + a * a - 2 * a * b * cos(hh);
    ans = sqrt(ans);
    cout << fixed << setprecision(10) << ans << endl;
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