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

vector<int> dp, sz, a;
vector<int> g[maxn];
void dfs(int u, int p = -1) {
    sz[u] = 1;
    dp[u] += a[u] == 1;
    dp[u] -= a[u] == 0;
    for (auto x : g[u]) {
        if (x == p)continue;
        dfs(x, u);
        dp[u] = max(dp[u], dp[u] + dp[x]);
        sz[u] += sz[x];
    }
}
vector<int> mx;
void change_root(int u, int v) {
    int a = dp[u], b = dp[v];
    if (b >= 0)a -= b;
    if (a >= 0)b += a;
    dp[u] = a, dp[v] = b;
}
void walk(int u, int p = -1) {
    mx[u] = max(mx[u], dp[u]);
    for (auto x: g[u]) {
        if (x == p) continue;
        change_root(u, x);
        mx[u] = max(mx[u], dp[u]);
        walk(x, u);
        change_root(x, u);
    }
}
void solve() {
    int n;
    cin >> n;
    dp = sz = a = vector<int>(n + 1, 0);
    mx = vector<int>(n + 1, -1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    debug2(dp);
    walk(1);
    debug2(mx);
    for (int i = 1; i <= n; i++)cout << mx[i] << " ";
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