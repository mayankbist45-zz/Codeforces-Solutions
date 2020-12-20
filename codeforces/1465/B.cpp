#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    auto check = [](int val) -> bool {
        string s = to_string(val);
        for (auto x : s) {
            if (x == '0')continue;
            if (val % (x - '0'))return false;
        }
        return true;
    };
    for (;; n++) {
        if (check(n)) {
            cout << n << endl;
            return;
        }
    }
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