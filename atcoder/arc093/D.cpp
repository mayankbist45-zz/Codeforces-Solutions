#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;

    vector<vector<char>> v(maxn, vector<char>(maxn));
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (i < maxn / 2)v[i][j] = '#';
            else v[i][j] = '.';
        }
    }
    a--, b--;
    for (int i = 0; i < maxn and a; i += 2) {
        for (int j = 0; j < maxn and a; j += 2)v[i][j] = '.', a--;
    }
    for (int i = maxn - 1; i >= 0 and b; i -= 2) {
        for (int j = 0; j < maxn and b; j += 2)v[i][j] = '#', b--;
    }
    cout << maxn << " " << maxn << endl;
    for (auto x: v) {
        for (auto j : x)cout << j;
        cout << endl;
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
