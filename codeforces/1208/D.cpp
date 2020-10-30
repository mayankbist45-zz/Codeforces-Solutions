#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int MOD = 1000000007;

/*
 * a1, a2, .... .. , an
 * p1, p2, .... .. , pn
 *
 * 1 at pos where pi = 0 but p1 is always 0
 * 1 at last pos p1 = 0
 * subtract 1 from all right elements
 * then find next rightmost 0 so on and so forth maybe
 * we will use segtree for
 * getting the rightmost 0 and subtracting in range
 * lazy propagation needed
 */

const int maxn = 200010, inf = 1e12;
pair<int, int> tree[4 * maxn];
int ar[maxn], lazy[4 * maxn];
pair<int, int> doit(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first)return a;
    if (b.first < a.first)return b;
    return {a.first, max(a.second, b.second)};
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index] = {ar[start], start};
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void divide(int index, int l, int r) {
    tree[index].first += lazy[index];
    if (l != r) {
        lazy[2 * index] += lazy[index];
        lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
}

pair<int, int> queryTree(int start, int end, int l, int r, int index = 1) {
    if (lazy[index] != 0) divide(index, start, end);
    if (r < start or l > end)return {LLONG_MAX, -1};
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int l, int r, int value, int index) {
    if (lazy[index] != 0) divide(index, start, end);
    if (r < start or l > end)return;
    if (l <= start and r >= end) {
        lazy[index] += value;
        divide(index, start, end);
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, l, r, value, 2 * index);
    update(mid + 1, end, l, r, value, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> ar[i];
    build(0, n - 1);
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        auto tp = queryTree(0, n - 1, 0, n - 1, 1);
        ans[tp.second] = i;
        update(0, n - 1, tp.second, tp.second, inf, 1);
        if (tp.second + 1 <= n - 1)
            update(0, n - 1, tp.second + 1, n - 1, -i, 1);
    }
    for (auto x:ans)cout << x << " ";
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