#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;
#define int long long

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
int pw(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1) % m;
    return pw(a * a % m, b / 2);
}
#undef int

vector<pair<int, int>> factors[1000010];
void solve() {
    sieve();
    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (!factors[v[i]].empty())continue;
        int tp = v[i];
        for (auto x: primes) {
            if (x * x > tp)break;
            int cnt = 0;
            while (tp % x == 0)tp /= x, cnt++;
            if (cnt) {
                mp[x] = max(mp[x], cnt);
                factors[v[i]].push_back({x, cnt});
            }
        }
        if (tp > 1)mp[tp] = max(mp[tp], 1), factors[v[i]].push_back({tp, 1});
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long ans = 1;
        for (auto x: factors[v[i]])mp[x.first] -= x.second;
        for (auto x: mp) (ans *= pw(x.first, x.second)) %= MOD;
        for (auto x: factors[v[i]])mp[x.first] += x.second;

        (sum += ans) %= MOD;
    }
    cout << sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;a

    while (t--)
        solve();
    return 0;
}