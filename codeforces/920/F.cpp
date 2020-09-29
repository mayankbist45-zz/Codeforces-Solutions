#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

//the function reduces to 0 really fast
int dp[maxn], ar[maxn];
pair<int, int> tree[4 * maxn];

pair<int, int> doit(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ans;
    ans.first = a.first + b.first;
    ans.second = max(a.second, b.second);
    return ans;
}

void build(int start, int end, int index = 1) {
    if (start == end) {
        tree[index] = {ar[start], ar[start]};
        return;
    }
    int mid = start + end >> 1;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}
pair<int, int> queryTree(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end) return {0, 0};
    if (l <= start and r >= end)return tree[index];
    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}
void update(int start, int end, int l, int r, int index) {
    if (r < start or l > end)return;
    if (start == end) {
        tree[index] = {dp[tree[index].first], dp[tree[index].first]};
        return;
    }
    int mid = start + end >> 1;
    if (tree[2 * index].second > 2)
        update(start, mid, l, r, 2 * index);
    if (tree[2 * index + 1].second > 2)
        update(mid + 1, end, l, r, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> ar[i];
    build(0, n - 1);
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)update(0, n - 1, l - 1, r - 1, 1);
        else cout << queryTree(0, n - 1, l - 1, r - 1, 1).first << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= maxn - 10; i++)
        for (int j = i; j <= maxn - 10; j += i)
            dp[j]++;

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}