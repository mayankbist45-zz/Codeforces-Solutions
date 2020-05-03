#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int x;
    cin >> x;

    for (int b = -118; b <= 119; b++) {
        for (int a = -118; a <= 119; a++) {
            int one = pow(abs(a), 5);
            int two = pow(abs(b), 5);

            if (a < 0)one *= -1;
            if (b < 0)two *= -1;

            int ans = one - two;
            if (ans == x) {
                cout << a << " " << b << endl;
                return;
            }
        }
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
