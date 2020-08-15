#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 200010

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query {
    int l, r, idx;
    int64_t ord;

    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};

inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

int BLOCK_SIZE;
int ans;
int v[maxn], cnt[1000010], answer[maxn];

void remove(int a) {
    ans -= v[a] * cnt[v[a]] * cnt[v[a]];
    cnt[v[a]]--;
    ans += v[a] * cnt[v[a]] * cnt[v[a]];
}

void add(int a) {
    ans -= v[a] * cnt[v[a]] * cnt[v[a]];
    cnt[v[a]]++;
    ans += v[a] * cnt[v[a]] * cnt[v[a]];
}

void solve() {
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<Query> queries(t);
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;

        l--, r--;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].idx = i;
        queries[i].calcOrder();
    }
    BLOCK_SIZE = sqrt(n);
    sort(queries.begin(), queries.end());

    int cl = 0, cr = 0;
    for (auto x: queries) {
        int l = x.l, r = x.r;
        while (cl < l) {
            remove(cl);
            cl++;
        }
        while (cl > l) {
            add(cl - 1);
            cl--;
        }
        while (cr <= r) {
            add(cr);
            cr++;
        }
        while (cr > r + 1) {
            remove(cr - 1);
            cr--;
        }
        answer[x.idx] = ::ans;
    }
    for (int i = 0; i < t; i++)
        cout << answer[i] << endl;
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