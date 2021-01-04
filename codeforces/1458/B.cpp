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


//#define int long long
#define endl '\n'
#define maxn 101
const int MOD = 1000000007;

vector<pair<int, int>> v;
int n;
int dp[maxn][maxn][maxn * maxn];

int solve(int pos, int k, int cap) {
    if (k == 0) {
        if (cap != 0)return INT_MIN;
        return 0;
    }
    if (pos == n)return INT_MIN;
    int &ans = dp[pos][k][cap];
    if (ans != -1)return ans;
    ans = solve(pos + 1, k - 1, cap - v[pos].first) + v[pos].second;
    ans = max(ans, solve(pos + 1, k, cap));
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    v = vector<pair<int, int>>(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int a = 0; a <= 10000; a++) {
            debug(i, a, solve(0, i, a));
            ans = max(ans, min(2 * a, solve(0, i, a) + sum));
        }
        cout << fixed << setprecision(15) << ans * 0.5 << " ";
    }
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