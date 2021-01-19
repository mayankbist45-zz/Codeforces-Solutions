#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
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

int ans[maxn];
void solve() {
    int d;
    cin >> d;

    int tp = *lower_bound(primes.begin(), primes.end(), d + 1);
    int zp = *lower_bound(primes.begin(), primes.end(), tp + d);
    cout << tp * zp << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
//    memset(ans, 63, sizeof ans);
//    for (int i = 0; i < primes.size(); i++) {
//        for (int j = i + 1; j < primes.size(); ++j) {
//            int val = min({primes[j] - primes[i], primes[i] - 1, primes[j] * primes[i] - primes[j]});
//            ans[val] = min(ans[val], primes[j] * primes[i]);
//        }
//    }
//
//    for (int i = 10000 - 1; i >= 1; i--)ans[i] = min(ans[i], ans[i + 1]);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}