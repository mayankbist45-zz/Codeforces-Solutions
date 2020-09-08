#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    set<pair<int, int>> st;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert({v[i], i});
    }
    if (accumulate(v.begin(), v.end(), 0ll) < k) {
        cout << -1 << endl;
        return;
    }
    int steps = 0, del = 0, it = 0, overall = 0;
    while (steps < k and !st.empty()) {
        auto tp = st.begin()->first - del;
        int lo = 1, hi = tp, mid, ans = -1;
        while (lo <= hi) {
            mid = lo + hi >> 1;
            if (st.size() * mid + steps <= k) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if (ans == -1) {
            break;
        } else if (ans != -1 and ans * st.size() + steps <= k) {
            del += ans;
            steps += st.size() * ans;
            if (ans == st.begin()->first)
                st.erase(st.begin());
            while (!st.empty() and st.begin()->first - del <= 0)st.erase(st.begin());
        }
    }
    vector<pair<int, int>> ans;
    for (auto x:st) { if (x.first - del > 0)ans.push_back({x.second, x.first - del}); }
    sort(ans.begin(), ans.end());

    int id = 0, cur = 0;
    for (; id < k - steps; id++)
        ans[id].second--;
    for (cur = id; cur < ans.size(); cur++)cout << ans[cur].first + 1 << " ";
    for (int i = 0; i < id; i++)if (ans[i].second > 0)cout << ans[i].first + 1 << " ";
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