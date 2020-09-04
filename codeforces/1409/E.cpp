#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> x, y;
int n, k;
int st[4 * maxn];

int doit(int a, int b) { return max(a, b); }

int queryst(int start, int end, int l, int r, int index = 1) {
    if (r < start or l > end)return 0;
    if (l <= start and r >= end)return st[index];
    int mid = start + end >> 1;
    return doit(queryst(start, mid, l, r, 2 * index), queryst(mid + 1, end, l, r, 2 * index + 1));
}

void update(int start, int end, int x, int val, int index) {
    if (x < start or x > end)return;
    if (start == end) {
        st[index] += val;
        return;
    }
    int mid = start + end >> 1;
    update(start, mid, x, val, 2 * index);
    update(mid + 1, end, x, val, 2 * index + 1);
    st[index] = doit(st[2 * index], st[2 * index + 1]);
}

int get_id(int fd) {
    int lo = 0, hi = x.size() - 1, mid, ans = n - 1;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (x[mid] <= fd) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return ans;
}

int get_id_back(int fd) {
    int lo = 0, hi = x.size() - 1, mid, ans = 0;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (x[mid] >= fd) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= 4 * n; i++)st[i] = 0;
    x = vector<int>(n);
    y = vector<int>(n);
    ordered_set st;
    for (int i = 0; i < n; i++)cin >> x[i], st.insert(x[i]);
    for (int i = 0; i < n; i++)cin >> y[i];
    sort(x.begin(), x.end());

    map<int, int> mp;
    int ans = 0;
    for (auto tp: x)mp[tp] = st.order_of_key(tp) + 1;
    vector<pair<int, int>> val;
    for (int i = 0; i < x.size(); i++) {
        if(i and x[i] == x[i - 1])continue;
        int node = x[i];
        int end = x[i] + k;
        int id = get_id(end);
        update(0, maxn - 10, mp[node], id - i + 1, 1);
        val.push_back({mp[node], id - i + 1});
    }
    for (int i = (int) x.size() - 1; i >= 0; i--) {
        int node = x[i];
        int end = x[i] - k;
        int id = get_id_back(end);
//        cout << i << " " <<  queryst(0, maxn - 10, mp[x[i]] + 1, maxn - 10, 1) << endl;
        ans = max(ans, queryst(0, maxn - 10, mp[x[i]] + 1, maxn - 10, 1) + i - id + 1);
    }
    cout << ans << endl;
    for(auto x: val)
        update(0, maxn - 10, x.first, -x.second, 1);

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