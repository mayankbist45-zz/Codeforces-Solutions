#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, x, y;

int getmx() {
    int sum = x + y;
    return max(1ll, min(sum - 1, n));
}

int getmn() {
    return min(n, max(x + y - n + 1, 1ll));
}

void solve() {
    cin >> n >> x >> y;
    cout << getmn() << " " << getmx() << endl;
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