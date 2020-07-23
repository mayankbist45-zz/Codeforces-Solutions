#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int MOD = 1000000007;

struct data {
    bool freq[26];

    data() {
        for (int i = 0; i < 26; i++)freq[i] = 0;
    }
};

const int maxn = 100010;
data tree[4 * maxn];
string s;

data doit(data a, data b) {
    data ret;
    for (int i = 0; i < 26; i++)ret.freq[i] = a.freq[i] | b.freq[i];
    return ret;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index].freq[s[start] - 'a'] = 1;
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

void update(int start, int end, int x, int val, int index) {
    if (x < start or x > end)
        return;

    if (start == end) {
        for (int i = 0; i < 26; i++)tree[index].freq[i] = 0;
        tree[index].freq[val] = 1;
        return;
    }

    int mid = start + end >> 1;
    if (x <= mid)update(start, mid, x, val, 2 * index);
    else update(mid + 1, end, x, val, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

int q;

void solve() {
    cin >> s >> q;
    build(0, (int) s.size() - 1);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p;
            char c;
            cin >> p >> c;
            update(0, (int) s.size() - 1, p - 1, c - 'a', 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            data d = queryTree(0, (int) s.size() - 1, l, r, 1);
            int ans = accumulate(d.freq, d.freq + 26, 0ll);
            cout << ans << endl;
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