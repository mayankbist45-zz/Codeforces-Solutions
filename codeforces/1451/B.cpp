#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        string tf = s.substr(a - 1, b - a + 1);
        int id = 0, gap = false;
        int rt = -1, lf = -1;
        for (int j = n - 1; j >= 0; j--)
            if (s[j] == tf.back()) {
                rt = j;
                break;
            }
        if (rt == -1) {
            cout << "NO" << endl;
            return;
        }

        for (int j = 0; j < n; j++) {
            auto x = s[j];
            if (id + 1 >= tf.size())break;
            if (x == tf[id])id++, lf = j;
            else if (id)gap = true;
        }

        if (!gap and lf + 1 < rt)gap = true;
        if (id + 1 != tf.size() or lf >= rt or !gap) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
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