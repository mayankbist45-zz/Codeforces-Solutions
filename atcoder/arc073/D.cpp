#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, w;
    cin >> n >> w;

    map<int, vector<int>> mp;
    int st = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (st == -1)st = a;
        mp[a].push_back(b);
    }
    for (auto &x: mp) {
        sort(x.second.rbegin(), x.second.rend());
        partial_sum(x.second.begin(), x.second.end(), x.second.begin());
    }
    int ans = 0;
    for (int i = 0; i <= mp[st + 3].size(); i++) {
        for (int j = 0; j <= mp[st + 2].size(); j++) {
            for (int k = 0; k <= mp[st + 1].size(); ++k) {
                for (int l = 0; l <= mp[st].size(); ++l) {
                    if (i * (st + 3) + j * (st + 2) + k * (st + 1) + l * st <= w) {
                        int val = 0;
                        if (i)val += mp[st + 3][i - 1];
                        if (j)val += mp[st + 2][j - 1];
                        if (k)val += mp[st + 1][k - 1];
                        if (l)val += mp[st][l - 1];
                        ans = max(ans, val);
                    }
                }

            }
        }
    }
    cout << ans << endl;
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