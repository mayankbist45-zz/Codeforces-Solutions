#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;;
    cin >> n;
    if (n % 2 == 0) {
        vector<int> val;

        while (n > 0) {
            val.push_back(1);
            n -= 2;
            int cur = 4;
            while (n >= cur and n) {
                n -= cur;
                val.push_back(0);
                cur *= 2;
            }
        }
        cout << val.size() << endl;
        for (auto x :val)cout << x << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
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