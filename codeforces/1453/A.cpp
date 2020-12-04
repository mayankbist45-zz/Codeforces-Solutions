#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >>  m;

    vector<int> v(n), b(m);
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert(v[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        st.insert(b[i]);
    }
    cout <<n + m - st.size() << endl;
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