#include<bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007
#define maxn 500010
#define endl '\n'
const int E = -1e14;
int n;
vector<pair<pair<int, int>, int>> queries;
int ans[maxn];
int a[maxn], t[maxn];

void update(int idx, int val) {
    while (idx <= n) {
        t[idx] += val;
        idx += idx & -idx;
    }
}

int pre(int idx) {
    int ans = 0;

    while (idx > 0) {
        ans += t[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int query(int l, int r) {
    return pre(r) - pre(l - 1);
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}

void solve() {
    sort(queries.begin(), queries.end(), comp);
    map<int, int> last;

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (last.count(a[i])) {
            update(last[a[i]], -1);
        }
        last[a[i]] = i + 1;
        update(i + 1, 1);
        while (counter < queries.size() and queries[counter].first.second == i + 1) {
            ans[queries[counter].second] = query(queries[counter].first.first, i + 1);
            counter++;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int q;
    cin >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < q; ++j) {
        int u, v;
        cin >> u >> v;

        queries.push_back({{u, v}, j});
    }
    solve();

    for (int i = 0; i < queries.size(); i++)
        cout << ans[i] << endl;
}
