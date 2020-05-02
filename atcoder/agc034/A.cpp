#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    string s;
    cin >> s;

    s = " " + s;
    if (c < d) {
        while (b < d) {
            if (b + 1 <= d and s[b + 1] != '#')
                b++;
            else if (b + 2 <= d and s[b + 2] != '#')
                b += 2;
            else
                break;
        }
        if (b != d) {
            cout << "No";
            return;
        }
        while (a < c) {
            if (a + 1 <= c and s[a + 1] != '#')
                a++;
            else if (a + 2 <= c and s[a + 2] != '#')
                a += 2;
            else break;
        }
        if (a != c) {
            cout << "No";
            return;
        }
        cout << "Yes";
        return;
    } else {
        for (int i = b; i <= d; i++) {
            if (s[i] != '#' and i + 1 <= n and s[i + 1] == '.' and i - 1 > 0 and s[i - 1] == '.' and i - 1 != a) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No";
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