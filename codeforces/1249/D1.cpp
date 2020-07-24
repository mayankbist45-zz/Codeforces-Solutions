#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<int, int>> v;
int n, k;

void solve() {
    cin >> n >> k;

    vector<int> val(210);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
        val[l]++, val[r + 1]--;
    }
    partial_sum(val.begin(), val.end(), val.begin());
    set<int> ans;
    for (int i = 1; i <= 200; i++) {
        while (val[i] > k) {
            int rd = -1, id = -1;
            for (int j = 0; j < n; j++) {
                if (ans.find(j) == ans.end() and v[j].first <= i and i <= v[j].second and (v[j].second > rd or id == -1))
                    id = j, rd = v[j].second;
            }
            ans.insert(id);
            for (int j = v[id].first; j <= v[id].second; j++)val[j]--;
        }
    }
    cout << ans.size() << endl;
    for (auto x: ans)cout << x + 1 << " ";
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