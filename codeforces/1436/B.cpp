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
    for (int i = 3; i * i <= n; i += 2)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += 2 * i)
                isPrime[j] = false;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
        if (isPrime[i])primes.push_back(i);
}

void solve() {
    int n;
    cin >> n;

    int prm = primes.back();
    int now = n - 1, val = -1;
    for (int i = primes.size() - 1; i >= 0; i--) {
        if (binary_search(primes.begin(), primes.end(), primes[i] - (n - 1)))continue;
        val = primes[i] - (n - 1);
        break;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == now)cout << val << " ", now--;
            else cout << 1 << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    sieve();
    while (t--)
        solve();
    return 0;
}