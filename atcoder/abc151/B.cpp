#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        cin >> v[i], sum += v[i];

    if (sum >= n * m) {
        cout << 0 << endl;
        return;
    }
    int x = n * m - sum;
    if (x > k)
        cout << -1;
    else
        cout << x << endl;
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