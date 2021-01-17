#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    string a, b;
    cin >> a >> b;

    int val = a.size() * b.size() / __gcd(a.size(), b.size());
    string one, two;
    while (one.size() < val)one += a;
    while (two.size() < val)two += b;

    ((one == two) ? cout << one : cout << -1);
    cout << endl;
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