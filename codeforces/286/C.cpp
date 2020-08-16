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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int t;
    cin >> t;

    for (int i = 0, q; i < t; i++)cin >> q, q--, v[q] = -v[q];
    stack<int> st;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    int need = n / 2 - t;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] < 0)st.push(-v[i]);
        else {
            if (st.empty() or st.top() != v[i]) {
                v[i] = -v[i];
                need--;
                st.push(-v[i]);
            } else {
                st.pop();
            }
        }
        if (need < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto x: v)cout << x << " ";
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