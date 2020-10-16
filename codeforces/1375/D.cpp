#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n;
int getmex(vector<int> &v) {
    vector<int> mp(n + 1, 0);
    for (auto x: v)mp[x]++;
    for (int i = 0; i <= n; i++) {
        if (mp[i])continue;
        return i;
    }
    return -1;
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> op;
    for (int i = 0; i < 2 * n; i++) {
        int mx = getmex(v);
        if (mx == n) {
            bool fd = false;
            for (int j = 0; j < v.size(); j++)
                if (v[j] != j) {
                    v[j] = mx;
                    fd = true;
                    op.push_back(j + 1);
                    break;
                }
            if (!fd)break;
        } else {
            op.push_back(mx + 1);
            v[mx] = mx;
        }
    }
    cout << op.size() << endl;
    for (auto x: op)cout << x << " ";
    cout << endl;
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