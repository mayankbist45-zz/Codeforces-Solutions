#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int one, two, three, mn = INT_MAX;

    auto solve = [&](int x, int y, int z) {
        int val = abs(a - x) + abs(b - y) + abs(c - z);
        if (z % y or z < y)return;
        if (val > mn)return;
        mn = val;
        one = x;
        two = y;
        three = z;
    };

    for (int i = 1; i <= 2 * a; i++) {
        for (int j = i; j <= 2 * b; j += i) {
            solve(i, j, (c / j) * j);
            solve(i, j, (c / j) * j + j);
        }
    }
    cout << mn << endl << one << " " << two << " " << three << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}