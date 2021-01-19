#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    n *= 2;
    vector<int> v(n);
    multiset<int> tp;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        tp.insert(v[i]);
    }
    sort(v.begin(), v.end());
    tp.erase(tp.find(v.back()));

    vector<pair<int, int>> ans;
    bool ok = true;

    for (int i = 0; i + 1 < n; i++) {
        int sum = v.back();
        multiset<int> st = tp;

        st.erase(st.find(v[i]));
        ans.clear();
        ok = true;

        while (!st.empty()) {
            int one = *st.rbegin(), two = -1;
            st.erase(st.find(one));
            if (!st.count(sum - one)) {
                ok = false;
                break;
            }
            two = sum - one;
            st.erase(st.find(two));
            ans.push_back({one, two});
            sum = max(one, two);
        }
        if (ok) {
            tp.clear();
            tp.insert(v[i]);
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << v.back() + *tp.begin() << endl;
    cout << v.back() << " " << *tp.begin() << endl;
    for (auto x: ans)cout << x.first << " " << x.second << endl;
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