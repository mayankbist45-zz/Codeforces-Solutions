#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

struct pot {
    int mx;
    int mn;
    int vl;
    pot() : mx(0), mn(0), vl(0) {}
};
vector<pot> tree;

pot doit(pot a, pot b) {
    pot c;
    c.vl = a.vl + b.vl;
    c.mn = min({a.mn, b.mn + a.vl});
    c.mx = max({a.mx, b.mx + a.vl});
    return c;
}
pot queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return pot();
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int x, int val, int index) {
    if (x < start or x > end)return;
    if (start == end) {
        tree[index].vl = val;
        if (val == -1)tree[index].mn = val;
        else tree[index].mx = val;
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, x, val, 2 * index);
    update(mid + 1, end, x, val, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    tree = vector<pot>(4 * n + 10);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        update(0, n - 1, i, (s[i] == '+' ? 1 : -1), 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pot ans = doit(queryTree(0, n - 1, 0, a - 1, 1), queryTree(0, n - 1, b + 1, n - 1, 1));
        cout << ans.mx - ans.mn + 1 << endl;
    }
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