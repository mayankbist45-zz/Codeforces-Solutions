#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

char rev(char ch) {
    return ch == '1' ? '0' : '1';
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (auto &x: a)cin >> x;
    for (auto &x: b)cin >> x;

    vector<int> vis(n);
//    something is not right and i have no fucking clue on how to solve this one
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int k = 0; k < n; k++) {
            if (vis[k])a[i][k] = rev(a[i][k]);
            ct += a[i][k] != b[i][k];
        }
        if (ct == n)continue;
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                if (vis[j] or i > 0) {
                    cout << "NO" << endl;
                    return;
                }
                vis[j] = 1;
            }
        }
    }
    cout << "YES" << endl;
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
