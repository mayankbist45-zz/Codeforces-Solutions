#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    vector<int> mp(26);
    for (auto x: s)mp[x - 'a']++;

    int m;
    cin >> m;

    set<pair<int, int>> st;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        st.insert({v[i], i});
    }
    int cur = 25;
    vector<char> ans(m);
    while (!st.empty()) {
        int times = 0;
        vector<int> v;
        while (!st.empty() and st.begin()->first == 0)times++, v.push_back(st.begin()->second), st.erase(st.begin());
        vector<pair<int, int>> tp;
        for (int i = cur; i >= 0; i--) {
            if (mp[i] >= times) {
                for (auto x: v)ans[x] = (char) (i + 'a');
                cur = i - 1;
                break;
            }
        }
        for (auto x: st) {
            int val = x.first;
            for (auto zp : v) val -= abs(x.second - zp);
            tp.push_back({val, x.second});
        }
        st.clear();
        for (auto x: tp)st.insert(x);
    }
    for (auto x: ans)cout << x;
    cout << endl;
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