#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
using int32 = __uint32_t;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    map<int,int> mp;
    mp[0]++;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i)
         v[i] += v[i - 1];
        ans += mp[v[i] % m];
        mp[v[i] % m]++;
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
