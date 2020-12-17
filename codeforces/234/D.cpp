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
#define maxn 110
const int MOD = 1000000007;


void setIO() {
    string s1 = "input", s2 = "output";
    freopen((s1 + ".txt").c_str(), "r", stdin);
    freopen((s2 + ".txt").c_str(), "w", stdout);
}

int win[maxn], big[maxn], small[maxn];
void solve() {
    int m, k;
    cin >> m >> k;
    for (int i = 0, tp; i < k; i++)cin >> tp, win[tp]++;
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int d;
        cin >> d;

        int ct = 0, canbe = 0;
        for (int j = 0, tp; j < d; j++) {
            cin >> tp;
            if (win[tp])ct++;
            else if (tp == 0)canbe++;
        }
        big[i] = min(k, ct + canbe);
        small[i] = d - min(d - ct, m - k);
    }
    for (int i = 0; i < n; i++) {
        bool w = true, l = false;
        for (int j = 0; j < n; ++j) {
            if (i == j)continue;
            if (big[i] < small[j])w = false;
            if (small[i] < big[j])l = true;
        }
        if (!l)cout << "0";
        else if (!w)cout << "1";
        else cout << "2";
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef KENECHI
    setIO();
#endif
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}