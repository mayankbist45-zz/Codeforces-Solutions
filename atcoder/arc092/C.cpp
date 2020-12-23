#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first + a.second == b.first + b.second)return a.first < b.first;
    return a.first + a.second < b.first + b.second;
}
int n;
vector<pair<int, int>> a, b;

int solve(int pos1, int pos2) {
    if (pos1 == n or pos2 == n)return 0;
    int ans = max(solve(pos1 + 1, pos2), solve(pos1, pos2 + 1));
    if (a[pos1].first < b[pos2].first and a[pos1].second < b[pos2].second) {
        ans = max(ans, 1 + solve(pos1 + 1, pos2 + 1));
    }
    return ans;
}

void solve() {
    cin >> n;
    a = b = vector<pair<int, int>>(n);
    for (auto &x: a)cin >> x.first >> x.second;
    for (auto &x: b)cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // all points are different
    set<int> st;
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < n and a[j].first < b[i].first)st.insert(-a[j].second), j++;
        auto tp = st.upper_bound(-b[i].second);
        if (tp == st.end())continue;
        st.erase(tp);
        ans++;
    }
    cout << ans << endl;
//    cout << solve(0, 0) << endl;

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