#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int lazy[4 * maxn][21], ar[maxn], tree[4 * maxn][21];

int doit(int a, int b) {
    return a + b;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        for (int i = 0; i <= 20; i++)
            tree[index][i] = (ar[start] >> i) & 1;
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    for (int i = 0; i <= 20; i++)
        tree[index][i] = doit(tree[2 * index][i], tree[2 * index + 1][i]);
}

void divide(int index, int l, int r, int id) {
    tree[index][id] = r - l + 1 - tree[index][id];
    if (l != r) {
        lazy[2 * index][id] ^= lazy[index][id];
        lazy[2 * index + 1][id] ^= lazy[index][id];
    }
    lazy[index][id] = 0;
}

int queryTree(int start, int end, int l, int r, int id, int index = 1) {
    if (lazy[index][id] != 0) divide(index, start, end, id);
    if (r < start or l > end)return 0;
    if (l <= start and r >= end)return tree[index][id];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, id, 2 * index), queryTree(mid + 1, end, l, r, id, 2 * index + 1));
}

void update(int start, int end, int l, int r, int value, int id, int index) {
    if (lazy[index][id] != 0) {
        divide(index, start, end, id);
    }

    if (r < start or l > end)
        return;

    if (l <= start and r >= end) {
        lazy[index][id] ^= value;
        if (lazy[index][id])divide(index, start, end, id);
        return;
    }

    int mid = start + end >> 1;
    update(start, mid, l, r, value, id, 2 * index);
    update(mid + 1, end, l, r, value, id, 2 * index + 1);
    tree[index][id] = doit(tree[2 * index][id], tree[2 * index + 1][id]);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)cin >> ar[i];
    build(0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int l, r, x;
        cin >> l >> r;
        if (t == 1) {
            int ans = 0;
            for (int i = 20; i >= 0; i--)
                ans += (1 << i) * queryTree(0, n - 1, l - 1, r - 1, i, 1);
            cout << ans << endl;
        } else {
            cin >> x;
            for (int i = 0; i <= 20; i++) {
                if ((x >> i) & 1)
                    update(0, n - 1, l - 1, r - 1, 1, i, 1);
            }
        }
    }
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