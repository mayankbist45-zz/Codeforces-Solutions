#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 500010
const int MOD = 1000000007;

string s;

int lazy[4 * maxn], ar[maxn], tree[4 * maxn];

int doit(int a, int b) {
    return a | b;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index] = 1 << (s[start] - '0');
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

void update(int start, int end, int x, char val, int index = 1) {
    if (x < start or x > end)
        return;

    if (start == end) {
        tree[index] = 1 << (val - '0');
        return;
    }

    int mid = start + end >> 1;
    update(start, mid, x, val, 2 * index);
    update(mid + 1, end, x, val, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    int n;
    cin >> n;
    cin >> s;

    build(0, n - 1);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            char ch;
            cin >> idx >> ch;
            idx--;

            update(0, n - 1, idx, ch);
        }
        else {
            int l, r;
            cin >> l>> r;

            cout << __builtin_popcount(queryTree(0, n- 1,l - 1, r- 1, 1)) << endl;
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