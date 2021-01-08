#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 500010
const int MOD = 1000000007;

vector<int> primes;
vector<int> d(maxn, 1);

void sieve(int n = maxn - 10) {
    d[1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            d[j] = i;
}

void solve() {
    sieve();
    int n;
    cin >> n;
    vector<int> v(d.begin() + 1, d.begin() + n + 1);
    sort(v.begin(), v.end());
    for (int i = 2; i <= n; i++)cout << v[i - 1] << " ";
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