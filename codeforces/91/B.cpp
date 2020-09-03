#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;


int st[4 * maxn];
int n;

//index, count
int doit(int a, int b) {
    return max(a, b);
}

int queryst(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return 0;
    if (l <= start and r >= end)return st[index];
    int mid = start + end >> 1;
    return doit(queryst(start, mid, l, r, 2 * index), queryst(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int x, int v1, int index) {
    if (x < start or x > end)return;
    if (start == end) {
        st[index] = v1;
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, x, v1, 2 * index);
    update(mid + 1, end, x, v1, 2 * index + 1);
    st[index] = doit(st[2 * index], st[2 * index + 1]);
}

void solve() {
    cin >> n;
    ordered_set stt;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        stt.insert(v[i]);
    }
    for (auto &x: v)x = stt.order_of_key(x) + 1;
    for (int i = 0; i < n; i++) update(0, maxn - 1, v[i], i, 1);

    for (int i = 0; i < n; i++) {
        auto cur = queryst(0, maxn - 1, 0, v[i] - 1, 1);
        cout << max(-1ll, cur - i - 1) << " ";
        if (queryst(0, maxn - 1, v[i], v[i], 1) == i)
            update(0, maxn - 1, v[i], -1, 1);
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