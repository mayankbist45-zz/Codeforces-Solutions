#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 55565
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
    sieve();
    int n;
    cin >> n;

    int ct = 0;
    for (long long prime : primes) {
        if (prime % 5 == 1) {
            ct++;
            cout << prime << " ";
        }
        if (ct == n)break;
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