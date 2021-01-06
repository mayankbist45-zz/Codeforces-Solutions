#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

int ar[maxn], tree[4 * maxn];

int doit(int a, int b) {
    return a ^ b;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index] = ar[start];
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

int queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)
        return 0;

    if (l <= start and r >= end)
        return tree[index];

    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}


void update(int start, int end, int x, int val, int index) {
    if (x < start or x > end)
        return;
    if (start == end) {
        tree[index] ^= val;
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, x, val, 2 * index);
    update(mid + 1, end, x, val, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    build(0, n - 1);
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            update(0, n - 1, x - 1, y, 1);
        } else {
            cout << queryTree(0, n - 1, x - 1, y - 1, 1) << endl;
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