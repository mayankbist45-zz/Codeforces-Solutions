#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<int, int>> v[maxn];
int n, k;

int lazy[4 * maxn], tree[4 * maxn];

int doit(int a, int b) {
    return max(a, b);
}

void divide(int index, int l, int r) {
    tree[index] += lazy[index];
    if (l != r) {
        lazy[2 * index] += lazy[index];
        lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
}

int queryTree(int start, int end, int l, int r, int index = 1) {
    if (lazy[index] != 0) {
        divide(index, start, end);
    }
    if (r < start or l > end)
        return LLONG_MIN;

    if (l <= start and r >= end)
        return tree[index];

    int mid = start + end >> 1;
    return doit(queryTree(start, mid, l, r, 2 * index), queryTree(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int l, int r, int value, int index) {
    if (lazy[index] != 0) {
        divide(index, start, end);
    }

    if (r < start or l > end)
        return;

    if (l <= start and r >= end) {
        lazy[index] += value;
        divide(index, start, end);
        return;
    }

    int mid = start + end >> 1;
    update(start, mid, l, r, value, 2 * index);
    update(mid + 1, end, l, r, value, 2 * index + 1);
    tree[index] = doit(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        update(1, 200000, l, r, 1, 1);
        v[l].push_back({r, i});
    }

    vector<int> ans(n);
    priority_queue<pair<pair<int, int>, int>> pq;
    for (int i = 0; i <= 200000; i++) {
        for (auto x: v[i])pq.push({{x.first, i}, x.second});
        int qu = queryTree(1, 200000, i, i, 1);
        while (qu > k) {
            auto top = pq.top();
            pq.pop();

            ans[top.second] = 1;
            update(1, 200000, top.first.second, top.first.first, -1, 1);
            qu--;
        }
    }
    cout << count(ans.begin(), ans.end(), 1) << endl;
    for (int i = 0; i < ans.size(); i++)if (ans[i] == 1)cout << i + 1 << " ";
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