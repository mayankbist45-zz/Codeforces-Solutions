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
#define maxn 410
const int MOD = 1000000007;
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<string> v(n);
    for (auto &j:v)cin >> j;
 
//    auto generateTop = [&](int i, int j, int bt = 1) -> vector<pair<int, int>> {
//        vector<pair<int, int>> ret;
//        while (i - bt >= 0 and i - bt < n and v[i - bt][j] == '0') {
//            i -= bt;
//            ret.push_back({i, j});
//        }
//        sort(ret.begin(), ret.end());
//        return ret;
//    };
//
//    auto generateRight = [&](int i, int j, int bt = 1) -> vector<pair<int, int>> {
//        vector<pair<int, int>> ret;
//        while (i - bt >= 0 and i - bt < n and j + 1 < m and v[i - bt][j + 1] == '0') {
//            i -= bt, j++;
//            ret.push_back({i, j});
//        }
//        sort(ret.begin(), ret.end());
//        return ret;
//    };
//
//    auto generateLeft = [&](int i, int j, int bt = 1) -> vector<pair<int, int>> {
//        vector<pair<int, int>> ret;
//        while (i - bt >= 0 and i - bt < n and j - 1 >= 0 and v[i - 1][j - 1] == '0') {
//            i--, j--;
//            ret.push_back({i, j});
//        }
//        sort(ret.begin(), ret.end());
//        return ret;
//    };
 
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(6, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i - 1][j - 1] == '1')continue;
            dp[i][j][0] += 1 + dp[i - 1][j][0];
            dp[i][j][1] += 1 + dp[i - 1][j - 1][1];
            dp[i][j][2] += 1 + dp[i - 1][j + 1][2];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            if (v[i - 1][j - 1] == '1')continue;
            dp[i][j][3] += 1 + dp[i + 1][j][3];
            dp[i][j][4] += 1 + dp[i + 1][j - 1][4];
            dp[i][j][5] += 1 + dp[i + 1][j + 1][5];
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '1')continue;
            int k = j;
            while (k + 1 < m and v[i][k] == '0')k++;
            for (int l = j; l <= k; l++) {
                for (int f = l + 1; f <= k; f++) {
                    int ta1 = dp[i + 1][l + 1][0], rt = dp[i + 1][l + 1][2];
                    int ta2 = dp[i + 1][f + 1][0], lt = dp[i + 1][f + 1][1];
 
                    if (lt - 1 >= f - l and ta1 - 1 >= f - l)ans++, ct++;
                    if (rt - 1 >= f - l and ta2 - 1 >= f - l)ans++, ct++;
 
                    if ((f - l + 1) & 1) {
                        ans += (rt - 1 >= (f - l) / 2 and lt - 1 >= (f - l) / 2);
                        ct += (rt - 1 >= (f - l) / 2 and lt - 1 >= (f - l) / 2);
                    }
 
                    ta1 = dp[i + 1][l + 1][3], rt = dp[i + 1][l + 1][5];
                    ta2 = dp[i + 1][f + 1][3], lt = dp[i + 1][f + 1][4];
 
                    if (lt - 1 >= f - l and ta1 - 1 >= f - l)ans++, ct++;
                    if (rt - 1 >= f - l and ta2 - 1 >= f - l)ans++, ct++;
 
                    if ((f - l + 1) & 1) {
                        ans += (rt - 1 >= (f - l) / 2 and lt - 1 >= (f - l) / 2);
                        ct += (rt - 1 >= (f - l) / 2 and lt - 1 >= (f - l) / 2);
                    }
                }
            }
            j = k;
        }
//        cout << ct << endl;
    }
    //count mid bois
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (v[row][col] == '1')continue;
            int j = row;
            while (j + 1 < n and v[j][col] == '0')j++;
 
            for (int i = row; i <= j; i++) {
                for (int k = i + 1; k <= j; k++) {
                    if ((k - i) & 1)continue;
                    int rt1 = dp[i + 1][col + 1][5], rt2 = dp[k + 1][col + 1][2];
                    if (rt1 -1 >= (k - i) / 2 and rt2 - 1 >= (k - i) / 2)ans++;
 
                    rt1 = dp[i + 1][col + 1][4], rt2 = dp[k + 1][col + 1][1];
                    if (rt1 - 1 >= (k - i) / 2 and rt2 - 1 >= (k - i) / 2)ans++;
                }
            }
            row = j;
        }
    }
    cout << ans << endl;
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