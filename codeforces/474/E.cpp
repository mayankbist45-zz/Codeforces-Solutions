#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct data {
    int a, pos;

    data() {
        a = 0, pos = -1;
    }
};

data st[4 * maxn];
int h[maxn], dp[maxn];

data doit(data a, data b) {
    if (a.a > b.a)return a;
    else return b;
}

data queryst(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)
        return data();//min value

    if (l <= start and r >= end)
        return st[index];

    int mid = start + end >> 1;
    return doit(queryst(start, mid, l, r, 2 * index), queryst(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int x, int val, int pos, int index) {
    if (x < start or x > end)
        return;
    if (start == end) {
        st[index].a = max(st[index].a, val);
        st[index].pos = pos;
        return;
    }
    int mid = start + end >> 1;
    if (x <= mid)update(start, mid, x, val, pos, 2 * index);
    else update(mid + 1, end, x, val, pos, 2 * index + 1);
    st[index] = doit(st[2 * index], st[2 * index + 1]);
}

map<int, int> mp;
int mx;

int getId(int val, bool islo = true) {
    int lo = 0, hi = mx, mid, ans = 0;
    if (islo) {
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (mp[mid] <= val) {
                lo = mid + 1;
                ans = mid;
            } else hi = mid - 1;
        }
        return ans;
    } else {
        ans = mx + 1;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (mp[mid] >= val) {
                hi = mid - 1;
                ans = mid;
            } else lo = mid + 1;
        }
        return ans;
    }
}


void solve() {
    int n, d;
    cin >> n >> d;

    //dp[i] = for all j < i and abs(v[j] - v[i]) >= d -> dp[i] = max(dp[i], 1 + dp[j])
    //will try to extract max using seg st
    ordered_set compressor;
    for (int i = 1; i <= n; i++)cin >> h[i], compressor.insert(h[i]);
    for (int i = 1; i <= n; i++) {
        int tp = h[i];
        h[i] = compressor.order_of_key(h[i]) + 1;
        mx = max(mx, h[i]);
        mp[h[i]] = tp;
    }
    mp[0] = LLONG_MIN;
    vector<int> par(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int ind = getId(mp[h[i]] - d);
        auto tp = queryst(1, n, 0, ind, 1);
        dp[i] = 1 + tp.a;
        par[i] = tp.pos;
        ind = getId(mp[h[i]] + d, false);

        tp = queryst(1, n, ind, 100000, 1);
        if (dp[i] < 1 + tp.a) {
            dp[i] = 1 + tp.a;
            par[i] = tp.pos;
        }
        update(1, n, h[i], dp[i], i, 1);
    }
    mx = 0;
    int cur = -1;
    for (int i = 1; i <= n; i++)if (dp[i] > mx)mx = dp[i], cur = i;
    cout << mx << endl;
    vector<int> path;
    while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    for (auto x: path)cout << x << " ";
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