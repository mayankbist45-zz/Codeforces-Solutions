#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b and b == c) {
        cout << "No" << endl;
        return;
    }
    set<int> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    if (st.size() == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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