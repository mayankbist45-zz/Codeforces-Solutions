#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
vector<int> val(51), sz(51);

int solve(int l, int x) {
    if (l == 0) return 1;
    if (x <= 1)return 0;
    if (x <= sz[l] / 2)return solve(l - 1, x - 1);
    if (x == sz[l] / 2 + 1)return 1 + val[l - 1];
    if (x < sz[l])return val[l - 1] + 1 + solve(l - 1, x - 1 - sz[l] / 2);
    return val[l];
}

void solve() {
    int n, x;
    cin >> n >> x;

//    string init = "P";
//    for (int i = 0; i < n; i++) {
//        string nw = 'B' + init + 'P' + init + 'B';
//        cout << nw << endl;
//        init = nw;
//    }
    cout << solve(n, x) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    val[0] = sz[0] = 1;
    for (int i = 1; i <= 50; i++)
        val[i] = 2 * val[i - 1] + 1, sz[i] = 3 + sz[i - 1] * 2;

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}