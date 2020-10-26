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
#define maxn 100010
const int MOD = 1000000007;

/*
 * i - rock
 * j - scissor
 * k - paper
 *
 * dp[i][j][k] - right now inhabited by i r and j s and k p
 * ans will be sum of dp[i][0][0], dp[0][j][0], dp[0][0][k]
 *
 * transitions:-
 *  dp[i][j][k] = dp[i + 1][j][k] * (i getting destroyed)
 *  and similar transitions
 */

void solve() {
    int r, s, p;
    cin >> r >> s >> p;

    vector<vector<vector<double>>> dp(r + 1, vector<vector<double>>(s + 1, vector<double>(p + 1)));
    dp[r][s][p] = 1;

    for (int i = r; i >= 0; i--) {
        for (int j = s; j >= 0; j--)
            for (int k = p; k >= 0; k--) {
                if (i and (j | k))
                    dp[i - 1][j][k] += dp[i][j][k] * ((double) (i * k) / (double) (i * j + j * k + k * i));
                if (j and (i | k))
                    dp[i][j - 1][k] += dp[i][j][k] * ((double) (i * j) / (double) (i * j + j * k + k * i));
                if (k and (i| j))
                    dp[i][j][k - 1] += dp[i][j][k] * ((double) (j * k) / (double) (i * j + j * k + k * i));
            }
    }
    debug2(dp);

    vector<double> ans(3, 0);
    for (int i = 1; i <= r; i++)ans[0] += dp[i][0][0];
    for (int i = 1; i <= s; i++)ans[1] += dp[0][i][0];
    for (int i = 1; i <= p; i++)ans[2] += dp[0][0][i];
    cout << fixed << setprecision(10);
    for (auto x: ans)cout << x << " ";
    cout << endl;
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