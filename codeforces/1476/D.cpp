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
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp1(2, vector<int>(n));
    vector<vector<int>> dp2(2, vector<int>(n));

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            dp1[0][i] = 1;
            if (i)
                dp1[0][i] += dp1[1][i - 1];
        } else {
            dp1[1][i] = 1;
            if (i)
                dp1[1][i] += dp1[0][i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            dp2[0][i] = 1;
            if (i + 1 < n)
                dp2[0][i] += dp2[1][i + 1];
        } else {
            dp2[1][i] = 1;
            if (i + 1 < n)
                dp2[1][i] += dp2[0][i + 1];
        }
    }
    debug2(dp1);
    debug2(dp2);
    cout << dp2[1][0] + 1 << " ";
    for (int i = 1; i < n; i++) {
        cout << dp2[1][i] + 1 + dp1[0][i - 1] << " ";
    }
    cout << dp1[0][n - 1] + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}