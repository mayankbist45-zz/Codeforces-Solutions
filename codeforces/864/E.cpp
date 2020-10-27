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
struct pot {
    int t, d, p, id;
    bool operator<(const pot &a) {
        return d < a.d;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<pot> v;
    v.push_back({0, LLONG_MIN, 0});
    for (int i = 0; i < n; i++) {
        int t, d, p;
        cin >> t >> d >> p;
        v.push_back({t, d, p, i + 1});
    }
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n + 1, vector<int>(4010, -1)), pre(n + 1, vector<int>(4010, LLONG_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2000; j++) {
            pre[i][j] = LLONG_MAX;
            dp[i][j] = dp[i - 1][j];
            if (j < v[i].d and j - v[i].t >= 0 and dp[i - 1][j - v[i].t] != -1) {
                if (dp[i][j] < dp[i - 1][j - v[i].t] + v[i].p)pre[i][j] = j - v[i].t;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].t] + v[i].p);
            }
        }
    }
    int mx = 0, id = -1;
    for (int i = 0; i <= 4000; i++) {
        if (dp[n][i] > mx)id = i;
        mx = max(mx, dp[n][i]);
    }
    vector<int> prt;
    int now = n;
    cout << mx << endl;
    if (mx == 0) {
        cout << 0 << endl;
        return;
    }
    while (now > 0) {
        if (pre[now][id] == LLONG_MAX) {
            now--;
            continue;
        } else if (pre[now][id] == LLONG_MIN) {
            break;
        } else {
            prt.push_back(v[now].id);
            id = pre[now][id];
            now--;
        }
    }
    cout << prt.size() << endl;
//    sort(prt.begin(), prt.end());
    reverse(prt.begin(), prt.end());
    for (auto x: prt)cout << x << " ";
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

