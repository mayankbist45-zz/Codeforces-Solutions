#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> v;
vector<pair<int, int>> tree;
int n;

pair<int, int> doit(pair<int, int> a, pair<int, int> b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index] = {v[start], v[start]};
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

pair<int, int> queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return {LLONG_MAX, LLONG_MIN};
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

int getMin(int l, int r) {
    return queryTree(0, n - 1, l, r, 1).first;
}
int getMax(int l, int r) {
    return queryTree(0, n - 1, l, r, 1).second;
}

pair<int, int> getBorder(vector<int> &vec, int val) {
    pair<int, int> ret;
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (vec[mid] == val) {
            ret.first = mid;
            hi = mid - 1;
        } else if (vec[mid] > val)lo = mid + 1;
        else hi = mid - 1;
    }
    lo = 0, hi = n - 1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (vec[mid] == val) {
            ret.second = mid;
            lo = mid + 1;
        } else if (vec[mid] > val)lo = mid + 1;
        else hi = mid - 1;
    }
    return ret;
}

void solve() {
    cin >> n;
    v = vector<int>(n);
    tree = vector<pair<int, int>>(4 * n + 10);
    for (int i = 0; i < n; ++i) cin >> v[i];
    build(0, n - 1);

    vector<int> suf(n);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = getMax(i, n - 1);

    //suf is decresing
    for (int i = 0; i + 2 < n; i++) {
        int preMx = getMax(0, i);

        pair<int, int> border = getBorder(suf, preMx);
        int lo = border.first, hi = border.second, mid;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            int val = getMin(i + 1, mid - 1);
            if (val == preMx) {
                cout << "YES" << endl;
                cout << i + 1 << " " << mid - 1 - i << " " << n - mid << endl;
                return;
            } else if (val < preMx) {
                hi = mid - 1;
            } else lo = mid + 1;
        }
    }
    cout << "NO" << endl;
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