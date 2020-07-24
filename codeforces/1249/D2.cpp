#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<int, int>> v[maxn];
int n, k;

int bit[maxn];

void add(int idx, int val) {
    for (; idx <= maxn - 10; idx += idx & (-idx))
        bit[idx] += val;
}

int pref(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= idx & (-idx))
        ans += bit[idx];
    return ans;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        add(l,1);
        add(r + 1, -1);
        v[l].push_back({r, i});
    }

    vector<int> ans(n);
    priority_queue<pair<pair<int, int>, int>> pq;
    for (int i = 0; i <= 200000; i++) {
        for (auto x: v[i])pq.push({{x.first, i}, x.second});
        int qu = pref(i);
        while (qu > k) {
            auto top = pq.top();
            pq.pop();

            ans[top.second] = 1;
            add(top.first.second, -1);
            add(top.first.first + 1, 1);
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