#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 2010
const int MOD = 1000000007;

template <int MOD=998'244'353>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
    Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

    Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
    Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
    Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
    friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
    friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

Modular<MOD> dp[maxn][maxn], lf[maxn][maxn], tp[maxn][maxn], dg[maxn][maxn];
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (auto &x: v)cin >> x;

    lf[0][0] = tp[0][0] = dg[0][0] = dp[0][0] = 1;
    for (int i = 1; i < h; i++) {
        if (v[i][0] == '#')break;
        dp[i][0] = lf[i - 1][0];
        lf[i][0] += lf[i - 1][0] + dp[i][0];
        tp[i][0] = dp[i][0];
        dg[i][0] = dp[i][0];
    }

    for (int i = 1; i < w; i++) {
        if (v[0][i] == '#')break;
        dp[0][i] = tp[0][i - 1];
        tp[0][i] += tp[0][i - 1] + dp[0][i];
        lf[0][i] = dp[0][i];
        dg[0][i] = dp[0][i];
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (v[i][j] == '#')continue;
            dp[i][j] = lf[i - 1][j] + tp[i][j - 1] + dg[i - 1][j - 1];
            lf[i][j] += dp[i][j] + lf[i - 1][j];
            tp[i][j] += dp[i][j] + tp[i][j - 1];
            dg[i][j] += dp[i][j] + dg[i - 1][j - 1];
        }
    }
    cout << dp[h - 1][w - 1] << endl;
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