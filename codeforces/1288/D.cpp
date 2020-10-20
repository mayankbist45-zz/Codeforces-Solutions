#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

template<typename T>
void make_set(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int getBit(int val, vector<int> &pro) {
    int ans = 0;
    for (int i = 0; i < pro.size(); i++)
        if (pro[i] >= val)ans |= (1 << i);
    return ans;
}

int l, r;
bool check(int val, vector<vector<int>> &v) {
    vector<int> st;
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++) {
        int cur = getBit(val, v[i]);
        st.push_back(cur);
        mp[cur] = i;
    }
    make_set(st);
    for (int i = 0; i < st.size(); i++)
        for (int j = i; j < st.size(); j++)
            if ((st[i] | st[j]) == (1 << v.front().size()) - 1) {
                l = mp[st[i]], r = mp[st[j]];
                return true;
            }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int lo = 0, hi = 1e9, mid;
    pair<int, int> ans = {-1, -1};
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (check(mid, v))ans = {l, r}, lo = mid + 1;
        else hi = mid - 1;
    }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
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