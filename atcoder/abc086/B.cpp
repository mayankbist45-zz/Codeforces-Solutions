#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

inline int stoii(string s) {
    int ans = 0;
    for (auto x:s)ans = ans * 10 + x - '0';
    return ans;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int z = stoii(to_string(a) + to_string(b));
    int tp = sqrt(z);
    if (tp * tp == z)
        cout << "Yes";
    else
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