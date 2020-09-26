#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

int n, k;
int bit[maxn];

int tree[4 * maxn], dp[maxn];

int doit(int a, int b) {
    return max(a, b);
}
int queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return 0;
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}
void update(int start, int end, int x, int val, int index) {
    if (x < start or x > end)return;
    if (start == end) {
        tree[index] = val;
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, x, val, 2 * index);
    update(mid + 1, end, x, val, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0] = 1;
    update(0, maxn - 1, v[0], 1, 1);
    for (int i = 1; i < v.size(); i++) {
        int lo = max(0ll, v[i] - k), hi = min((int) maxn - 10, v[i] + k);
        dp[i] = 1;
        dp[i] = max(dp[i], 1 + queryTree(0, maxn - 1, lo, hi, 1));
        update(0, maxn - 1, v[i], dp[i], 1);
    }
    cout << *max_element(dp, dp + n) << endl;
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