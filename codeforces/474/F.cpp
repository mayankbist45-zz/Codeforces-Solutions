#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct data {
    int gcd, mn, occ;

    data() {
        gcd = 0, mn = LLONG_MAX, occ = 1;
    }
};

int ar[maxn];
data tree[4 * maxn];

data doit(data a, data b) {
    data ret;
    ret.gcd = __gcd(a.gcd, b.gcd);
    if (a.mn == b.mn)ret.mn = a.mn, ret.occ = a.occ + b.occ;
    else if (a.mn < b.mn)ret.mn = a.mn, ret.occ = a.occ;
    else ret.mn = b.mn, ret.occ = b.occ;
    return ret;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index].gcd = tree[index].mn = ar[start];
        tree[index].occ = 1;
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

data queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)
        return data();

    if (l <= start and r >= end)
        return tree[index];

    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> ar[i];
    build(0, n - 1);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        auto data = queryTree(0, n - 1, a, b, 1);
//        cout << data.occ << " " << data.gcd << " " << data.mn << endl;
        if (data.mn == data.gcd)cout << (b - a + 1) - data.occ << endl;
        else cout << b - a + 1 << endl;
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