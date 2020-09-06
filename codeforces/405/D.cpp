#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int maxn = 1000000;
const int MOD = 1000000007;

int vis[maxn + 10];

inline int rev(int a) {
    return maxn - a + 1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        vis[v[i]] = 1;
    }
    int cut = 0;
    vector<int> ans;
    for (int i = 1; i <= maxn; i++) {
        if (vis[i]) {
            if (!vis[rev(i)])
                ans.push_back(rev(i));
            else cut++;
        }
    }
    for (int i = 1; i <= maxn and cut > 0; i++) {
        if (!vis[i] and !vis[rev(i)]) {
            cut -= 2;
            ans.push_back(i);
            ans.push_back(rev(i));
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)cout << x << " ";
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