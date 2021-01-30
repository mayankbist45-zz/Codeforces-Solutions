#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        if (a > b)cout << "Takahashi";
        else cout << "Aoki";
    } else {
        if (b > a)
            cout << "Aoki";
        else cout << "Takahashi";
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