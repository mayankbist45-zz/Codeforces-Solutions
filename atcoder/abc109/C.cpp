#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >>  x;

    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    v[n] = x;

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = __gcd(ans, v[i] - v[i - 1]);
    cout << ans << endl;
}