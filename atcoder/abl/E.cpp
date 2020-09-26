#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 998244353;

int pww(int a, int b, int m = MOD) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pww(a, b - 1) % m;
    return pww(a * a % m, b / 2);
}
int inverse(int a) {
    return pww(a, MOD - 2);
}
int pw[maxn];
int val;
int lazy[4 * maxn], tree[4 * maxn];
int doit(int a, int b, int diff) {
    return (a * pw[diff] % MOD + b) % MOD;
}
int some(int l) {
    int cur = pw[l] - 1 + MOD;
    if (cur >= MOD)cur -= MOD;
    cur *= val;
    cur %= MOD;
    return cur;
}
void divide(int index, int l, int r) {
    //dddddddddddd
    tree[index] = (lazy[index] * some(r - l + 1) % MOD);
    if (l != r) {
        lazy[2 * index] = lazy[index];
        lazy[2 * index + 1] = lazy[index];
    }
    lazy[index] = 0;
}
int queryTree(int start, int end, int l, int r, int index = 1) {
    if (lazy[index] != 0) divide(index, start, end);
    if (r < start or l > end)return 0;
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1), end - mid);
}
void update(int start, int end, int l, int r, int value, int index) {
    if (lazy[index] != 0) divide(index, start, end);
    if (r < start or l > end)return;
    if (l <= start and r >= end) {
        lazy[index] = value;
        divide(index, start, end);
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, l, r, value, 2 * index);
    update(mid + 1, end, l, r, value, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1], end - mid);
}
void solve() {
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pw[i] = pw[i - 1] * 10 % MOD;
    }
    val = inverse(9);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)update(0, n - 1, i, i, 1, 1);
//    cout << tree[1] << endl;
    for (int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        update(0, n - 1, l - 1, r - 1, d, 1);
        cout << tree[1] << endl;
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