#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int k, t;
    cin >> k >> t;

    vector<int> v(k);
    vector<pair<int, int>> val(t);
    for (int i = 0; i < t; ++i) {
        cin >> v[i];
        val[i] = {i + 1, v[i]};
    }
    sort(val.begin(), val.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    vector<int> ans(k);
    int id = 0;
    bool fl = false;
    for (auto &x: val) {
        if (id >= k)
            id = 1;
        if (!fl)
            for (; x.second > 0; id += 2) {
                if (x.second == 0)break;
                if (id >= k) {
                    fl = true;
                    break;
                }
                ans[id] = x.first;
                x.second--;
            }
        if (fl) {
            if (k % 2 == 0) {
                if (id >= k)
                    id = k - 1;
                for (; x.second > 0; id -= 2) {
                    if (x.second == 0)break;
                    ans[id] = x.first;
                    x.second--;
                }
            } else {
                if (id >= k)
                    id = 1;
                for (; x.second > 0; id += 2) {
                    if (x.second == 0)break;
                    ans[id] = x.first;
                    x.second--;
                }
            }
        }
    }
//    for (auto x: ans)cout << x << " ";
    cout << endl;
    int ct = 0;
    for (int i = 1; i < k; i++)if (ans[i] == ans[i - 1])ct++;
    cout << ct << endl;
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
