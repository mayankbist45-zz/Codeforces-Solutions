#include <bits/stdc++.h>

using namespace std;

#define int long long
#define maxn 100010
const int MOD = 1000000007;

struct interact {
    int query(vector<int> &a) {
        int ret;
        cout << "? ";
        for (auto x: a)cout << x << " ";
        cout << endl;
        cin >> ret;
        return ret;
    }

    void write(int result) {
        cout << "! " << result << endl;
    }
};

interact it;
void solve() {
    vector<int> a;
    for (int i = 1; i <= 100; i++) a.push_back(i);
    int res = it.query(a), x = 0;
    for (int i = 7; i < 14; i++)
        if ((res >> i) & 1)x |= (1 << i);
    a.clear();
    for (int i = 1; i <= 100; i++)a.push_back(i << 7);
    res = it.query(a);
    for (int i = 0; i < 7; i++)
        if (res >> i & 1)x |= (1 << i);
    it.write(x);
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