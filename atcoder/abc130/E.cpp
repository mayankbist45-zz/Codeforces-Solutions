#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct mint {
    const int mod = 1e9 + 7;
    long long x;

    mint(long long x = 0) : x((x % mod + mod) % mod) {}

    mint &operator=(const long long a) {
        x = a % mod;
        return *this;
    }

    mint &operator=(const mint a) {
        x = a.x % mod;
        return *this;
    }

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint &operator-=(const mint a) {
        if ((x += (mod - a.x)) >= mod) x -= mod;
        return *this;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n), s(m);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < m; i++)cin >> s[i];

    vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
//    for(int i = 0; i <= n; i++)dp[i][0] = 1;
//    for(int i = 0; i <= m; i++)dp[0][i] = 1;
//    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i - 1] == s[j - 1])dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + 1);
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]);
        }
    }
    dp[n][m] += 1;
    cout << dp[n][m].x << endl;
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

