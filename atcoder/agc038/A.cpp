#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    for (int i = 0; i < h; cout << endl, i++)
        for (int j = 0; j < w; j++) {
            if (i < b and j < a)cout << 0;
            else if (i < b and j >= a)cout << 1;
            else if (i >= b and j < a)cout << 1;
            else cout << 0;
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