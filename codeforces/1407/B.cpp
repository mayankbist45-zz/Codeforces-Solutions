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
    vector<int> ans, vis(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0, id = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] and mx < __gcd(v[j], cur)) {
                id = j;
                mx = __gcd(v[j], cur);
            }
        }
        vis[id] = 1;
        ans.push_back(v[id]);
        cur = __gcd(cur, v[id]);
    }
    for (auto x: ans)cout << x << " ";
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