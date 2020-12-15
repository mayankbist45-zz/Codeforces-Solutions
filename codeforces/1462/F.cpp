#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct fenwick {
    int n;
    vector<int> bit;

    fenwick(int _n) : bit(_n), n(_n) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx] += val;
    }

    int pref(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & (-idx))
            ans += bit[idx];
        return ans;
    }

    int sum(int a, int b) { return pref(b) - pref(a - 1); }
};

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}
void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, -i});
        v.push_back({b, i});
    }
    sort(v.begin(), v.end());
    map<int, int> mp;
    int ans = LLONG_MAX;

    fenwick fw(v.size() + 2);
    vector<pair<pair<int, int>, int>> queries;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second < 0)mp[abs(v[i].second)] = i;
        else {
            queries.push_back({{mp[v[i].second], i}, i});
//            ans = min(ans, n - fw.sum(mp[v[i].second] + 1, i + 1));
        }
    }


//    https://www.spoj.com/status/DQUERY,kenechi/
    sort(queries.begin(), queries.end(), comp);
    map<int, int> last;

    int counter = 0;
    for (int i = 0; i < v.size(); i++) {
        if (last.count(abs(v[i].second))) {
            fw.add(last[abs(v[i].second)], -1);
        }
        last[abs(v[i].second)] = i + 1;
        fw.add(i + 1, 1);
        while (counter < queries.size() and queries[counter].first.second == i) {
            ans = min(ans, n - fw.sum(queries[counter].first.first + 1, i + 1));
            counter++;
        }
    }
    cout << ans << endl;
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