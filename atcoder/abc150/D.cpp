#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans = lcm(ans, v[i] / 2);
        v[i] /= 2;
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if ((ans / v[i]) % 2 == 0)
            flag = false;
    }
    if (!flag)
        cout << 0 << endl;
    else
        cout << (m / ans + 1) / 2 << endl;
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