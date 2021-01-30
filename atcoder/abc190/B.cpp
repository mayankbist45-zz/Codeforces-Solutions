#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, s, d;
    cin >> n >> s >> d;
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        if (b <= d or a >= s)continue;
        ct++;
    }
    cout << (ct ? "Yes":"No");
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