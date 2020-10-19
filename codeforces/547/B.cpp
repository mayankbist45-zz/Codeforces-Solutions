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
    auto fro = [&]() -> vector<int> {
        vector<int> val(n);
        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() and v[st.top()] >= v[i])st.pop();
            if (st.empty())val[i] = -1;
            else val[i] = st.top();
            st.push(i);
        }
        return val;
    };
    auto rev = [&]() -> vector<int> {
        vector<int> val(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and v[st.top()] >= v[i])st.pop();
            if (st.empty())val[i] = n;
            else val[i] = st.top();
            st.push(i);
        }
        return val;
    };
    vector<int> l(n), r(n);
    l = fro();
    r = rev();

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int rg = r[i] - l[i] - 1;
        ans[rg] = max(ans[rg], v[i]);
    }
    for (int i = n - 1; i >= 0; i--)ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++)cout << ans[i] << " ";
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