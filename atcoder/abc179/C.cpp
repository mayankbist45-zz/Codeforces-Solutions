#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

vector<int> primes;
vector<bool> isPrime(maxn, true);
int pre[maxn];

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

    cout << pre[n - 1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    for (int i = 1; i <= maxn - 10; i++) {
        int cur = i, val = 1;
        for (auto x: primes) {
            if (x * x > cur)break;
            int ct = 0;
            while (cur % x == 0)cur /= x, ct++;
            val *= (ct + 1);
        }
        if (cur > 1)val *= 2;
        pre[i] = val + pre[i - 1];
    }
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}