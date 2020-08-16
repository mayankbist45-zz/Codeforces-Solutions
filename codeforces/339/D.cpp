#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 200010
 
int v[maxn], tree[4 * maxn];
 
void build(int start, int end, int index, int lvl) {
    if (start == end) {
        tree[index] = v[start];
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index, lvl - 1);
    build(mid + 1, end, 2 * index + 1, lvl - 1);
 
    if (lvl % 2 == 0)
        tree[index] = tree[2 * index] ^ tree[2 * index + 1];
    else
        tree[index] = tree[2 * index] | tree[2 * index + 1];
}
 
int queryTree(int start, int end, int l, int r, int index, int lvl) {
    if (r < start or l > end)
        return 0;
 
    if (l <= start and r >= end)
        return tree[index];
 
    int mid = start + end >> 1;
    queryTree(start, mid, l, r, index << 1, lvl - 1);
    queryTree(mid + 1, end, l, r, index << 1 | 1, lvl - 1);
    if (lvl % 2 == 0)
        tree[index] = tree[2 * index] ^ tree[2 * index + 1];
    else
        tree[index] = tree[2 * index] | tree[2 * index + 1];
    return tree[index];
}
 
void update(int start, int end, int x, int val, int index, int lvl) {
    if (start == end) {
        tree[index] = val;
        return;
    }
 
    int mid = start + end >> 1;
 
    if (x <= mid)
        update(start, mid, x, val, 2 * index, lvl - 1);
    else
        update(mid + 1, end, x, val, 2 * index + 1, lvl - 1);
 
    if (lvl % 2 == 0)
        tree[index] = tree[2 * index] ^ tree[2 * index + 1];
    else
        tree[index] = tree[2 * index] | tree[2 * index + 1];
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < (1 << n); i++) {
        cin >> v[i];
    }
 
    build(0, (1 << n) - 1, 1, n);
//    cout << queryTree(0, (1 << n) - 1, 0, (1 << n) - 1, 1, n) << endl;
 
    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
 
        update(0, (1 << n) - 1, p - 1, b, 1, n);
        cout << queryTree(0, (1 << n) - 1, 0, (1 << n) - 1, 1, n) << endl;
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
