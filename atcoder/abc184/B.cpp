#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    if (x < 0)x = 0;
    for (int i = 0; i < n; i++) {
        x += s[i] == 'o';
        x -= s[i] == 'x';
        if (x < 0)x = 0;
    }
    cout << x ;
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