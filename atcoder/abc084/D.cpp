#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> primes;
vector<bool> isPrime(maxn, true);
int ans[maxn];

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
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << ans[b] - ans[a - 1] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    for (int i = 1; i <= maxn - 10; i++) {
        if (i & 1) {
            if (isPrime[i] and isPrime[(i + 1) / 2] and (((i + 1) / 2) % 2 != 0 or (i + 1) / 2 == 2))
                ans[i] = 1;
        }
        ans[i] += ans[i - 1];
    }

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}