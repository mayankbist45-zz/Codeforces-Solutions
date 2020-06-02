#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int b = 0, w = 0;
    for (auto x: s)if (x == '#')b++; else w++;
    int ans = min(w, b);
    int cura = 0, curb = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#')curb++; else cura++;
        ans = min(ans, curb + (w - cura));
    }
    cout << ans << endl;
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