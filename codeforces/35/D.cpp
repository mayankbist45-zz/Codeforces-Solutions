#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int c[maxn], n, x;

void solve() {
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] = (n - i) * c[i];
    }
    sort(c, c + n);
    int id = 0, pos = 0;
    while (pos < n and c[pos] + id <= x)
        id += c[pos], pos++;
    cout << pos << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO();
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}