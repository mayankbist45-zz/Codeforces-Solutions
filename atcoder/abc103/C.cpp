#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    int ans = 0, lc = 1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        ans += v[i] - 1;
    }
    cout << ans << endl;
}