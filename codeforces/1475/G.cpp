//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 200010
//const int MOD = 1000000007;
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<string>a(n), b(n);
//    for(auto &x: a)cin >> x;
//    for(auto &x: b)cin >> x;
//
//
//}
//
//int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t = 1;
////    cin >> t;
//
//    while (t--)
//        solve();
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> divisors[maxn];
vector<int> maxValue, font;

vector<int> getDivisors(int val) {
    vector<int> ret;
    for (int i = 1; i * i <= val; i++) {
        if (val % i)continue;
        ret.push_back(i);
        if (val / i == i)continue;
        ret.push_back(val / i);
    }
    return ret;
}
struct disjoint_set {
    vector<int> par, cost, sz;
    disjoint_set(int n) : par(n + 1), cost(n + 1), sz(n + 1, 0) {
        iota(par.begin(), par.end(), 0ll);
    }
    int find(int x) { return par[x] = (x == par[x] ? x : find(par[x])); }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

void solve() {
    maxValue = vector<int>(maxn, 0);
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
//    disjoint_set dsu(maxn);
//    for (auto x: mp) {
//        dsu.sz[x.first] = x.second;
//    }
    for (int i = 0; i < n; i++) {
        if (divisors[v[i]].empty())divisors[v[i]] = getDivisors(v[i]);
        int cur = 1;
        for (auto x: divisors[v[i]]) {
            cur = max(cur, 1 + maxValue[x]);
        }
        maxValue[v[i]] = max(cur, maxValue[v[i]]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, maxValue[v[i]]);
    }
    cout << min(n - mx, n - 1) << endl;
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