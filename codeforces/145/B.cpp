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

vector<char> print;
bool solve(vector<int> a, string s1, string s2) {
    string ans;
    a[3] -= (a[2] - 1);
    while (a[2] > 0) ans += s1, a[2]--;
    if (a[3] > 0) ans += s2.back(), a[3]--;
    while (a[3] > 0) ans += s2, a[3]--;
    int id = -1;
    for (int i = 0; i < ans.size(); i++) {
        auto x = ans[i];
        a[0] -= x == '4', a[1] -= x == '7';
        if (x == '7')id = i;
    }
    print.clear();
    for (int i = 0; i < ans.size(); i++) {
        print.push_back(ans[i]);
        if (ans[i] == '4')while (a[0]-- > 0)print.push_back('4');
        if (ans[i] == '7' and id == i)while (a[1]-- > 0)print.push_back('7');
    }
    return true;
}

bool check(vector<int> v) {
    for (int i = 0; i < print.size(); i++) {
        v[0] -= print[i] == '4';
        v[1] -= print[i] == '7';

        if (i + 1 < print.size()) {
            string tp;
            tp += print[i];
            tp += print[i + 1];
            v[2] -= tp == "47";
            v[3] -= tp == "74";
        }
    }
    return count(v.begin(), v.end(), 0) == 4;
}

void write() {
    for (auto x: print)cout << x;
    exit(0);
}

void solve() {
    vector<int> a(4);
    for (auto &x: a)cin >> x;

    vector<int> v = a;
    if (abs(a[2] - a[3]) > 1) {
        cout << "-1" << endl;
        return;
    }
    //otherwise
    string s1 = "47", s2 = "74", ans;
    if (solve(a, s1, s2) and check(v))write();
    swap(a[2], a[3]);
    if (solve(a, s2, s1) and check(v))write();
    cout << -1 << endl;
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