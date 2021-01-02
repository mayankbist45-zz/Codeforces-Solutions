#include <bits/stdc++.h>

using namespace std;

#define int long long
#define maxn 200010
const int MOD = 1000000007;

struct interact {
    int query(int a, int b, string s) {
        int ret;
        cout << s << " " << a << " " << b << endl;
        cin >> ret;
        return ret;
    }
    void write(vector<int> &ans) {
        cout << "! ";
        for (auto x: ans)
            cout << x << " ";
        cout << endl;
    }
};

string s[] = {"AND", "OR", "XOR"};
void solve() {
    interact it;
    int n;
    cin >> n;

    vector<int> store;
    auto sumQuery = [&](int a, int b) -> int {
        int val = it.query(a, b, s[2]);
        store.push_back(val);
        val += 2 * it.query(a, b, s[0]);
        return val;
    };
    // A + B = A ^ B + 2 * (A & B)
    vector<int> v = {
            sumQuery(1, 2),
            sumQuery(2, 3),
            it.query(1, 3, s[0]) * 2 + (store.front() ^ store.back())
    };
    vector<int> ans;
    int a = (v[2] - v[1] + v[0]) / 2;
    int b = v[0] - a;
    int c = v[1] - b;
    ans = {a, b, c};
    for (int i = 4; i <= n; i++)
        ans.push_back(it.query(1, i, s[2]) ^ a);
    it.write(ans);
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