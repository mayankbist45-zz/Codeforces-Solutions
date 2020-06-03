#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> primes;
vector<bool> isPrime(maxn, true);

void sieve(int n = maxn - 10) {
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 3; i * i <= n; i += 2)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += 2 * i)
                isPrime[j] = false;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
        if (isPrime[i])primes.push_back(i);
}

void solve() {
    sieve();
    int q;
    cin >> q;

    vector<int> v(maxn);
    for (int i = 3; i <= maxn - 10; i += 2) {
        int b = (i + 1) / 2;
        if ((b & 1 or b == 2) and isPrime[b] and isPrime[i])
            v[i] = 1;
    }
    partial_sum(v.begin(), v.end(), v.begin());
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }
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