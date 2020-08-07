#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }

    int q;
    cin >> q;
    multiset<int> st;
    for (auto x: mp)
        st.insert(x.second);
    for (int i = 0; i < q; i++) {
        char ch;
        int x;
        cin >> ch >> x;

        if (ch == '+') {
            if (mp.count(x))st.erase(st.find(mp[x]));
            mp[x]++;
        } else {
            st.erase(st.find(mp[x]));
            mp[x]--;
        }
        st.insert(mp[x]);
        vector<int> som;
        for (auto it = st.rbegin(); it != st.rend() and som.size() < 3; it++)
            som.push_back(*it);
        bool can = true;
        if (som.empty()) {
            can = false;
        } else if (som.size() == 1 and som[0] < 8) {
            can = false;
        } else if (som.size() == 2) {
            if (som[0] < 4)can = false;
            else {
                som[0] -= 4;
                sort(som.begin(), som.end());
                if (som.back() >= 4 or (som.back() >= 2 and som[0] >= 2)) {

                } else can = false;
            }
        } else if (som.size() == 3) {
            if (som[0] < 4)can = false;
            else {
                som[0] -= 4;
                sort(som.begin(), som.end());
                if (som.back() >= 4 or (som.back() >= 2 and som[1] >= 2)) {

                } else can = false;
            }
        }

        if (can) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
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