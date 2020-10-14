#include <bits/stdc++.h>

using namespace std;
#ifdef KENECHI

template<typename L, typename R>
ostream &operator<<(ostream &out, const pair<L, R> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<typename Tuple, size_t N>
struct TuplePrinter {
    static ostream &print(ostream &out, const Tuple &t) {
        return TuplePrinter<Tuple, N - 1>::print(out, t) << ", " << get<N - 1>(t);
    }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
    static ostream &print(ostream &out, const Tuple &t) { return out << get<0>(t); }
};

template<typename... Args>
ostream &print_tuple(ostream &out, const tuple<Args...> &t) {
    return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}

template<typename ...Args>
ostream &operator<<(ostream &out, const tuple<Args...> &t) {
    return print_tuple(out, t);
}

template<typename T>
ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr) {
    out << "{";
    for (auto &x: arr) out << x << ", ";
    return out << (arr.size() ? "\b\b" : "") << "}";
}

template<size_t S>
ostream &operator<<(ostream &out, const bitset<S> &b) {
    for (int i = 0; i < S; ++i) out << b[i];
    return out;
}

void debug_out() { cerr << "\b\b " << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << H << ", ", debug_out(T...); }

void debug2_out() { cerr << "-----DEBUG END-----\n"; }

template<typename Head, typename... Tail>
void debug2_out(Head H, Tail... T) {
    cerr << "\n";
    for (auto x: H) cerr << x << "\n";
    debug2_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif

#define int long long
#define endl '\n'
#define maxn 300010
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

long long compute_hash(string const &s, int prm) {
    int p = prm;
    long long hash_value = 0, p_pow = 1, id = 0;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = p_pow * p % MOD;
    }
    return hash_value;
}

void solve() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert({compute_hash(s, 31), compute_hash(s, 53)});
    }
    for (int id = 0; id < m; id++) {
        string s;
        cin >> s;
        int p1 = 1, p2 = 1;
        mint hash1 = compute_hash(s, 31), hash2 = compute_hash(s, 53);
        bool fd = false;
        for (int i = 0; i < s.size(); i++) {
            hash1 = hash1 - p1 * (s[i] - 'a' + 1) % MOD;
            hash2 = hash2 - p2 * (s[i] - 'a' + 1) % MOD;
            for (auto x: {0, 1, 2}) {
                hash1 += p1;
                hash2 += p2;
                if (s[i] == 'a' + x)continue;
                if (st.count({hash1.x, hash2.x})) {
                    cout << "YES" << endl;
                    fd = true;
                    break;
                }
            }
            hash1 -= 3 * p1 % MOD;
            hash2 -= 3 * p2 % MOD;
            hash1 += p1 * (s[i] - 'a' + 1) % MOD;
            hash2 += p2 * (s[i] - 'a' + 1) % MOD;
            if (fd)break;
            p1 = p1 * 31 % MOD;
            p2 = p2 * 53 % MOD;
        }
        if (!fd)
            cout << "NO" << endl;
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