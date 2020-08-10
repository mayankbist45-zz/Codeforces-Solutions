#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {if (v[i][m - 1] != 'D')ans++;}
    for (int i = 0; i < m - 1; i++) {if (v[n - 1][i] != 'R')ans++;}
    cout << ans << endl;
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