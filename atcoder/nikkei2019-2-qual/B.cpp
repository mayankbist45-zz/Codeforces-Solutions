#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> d(n);
    for(int i = 0; i < n; i++)cin >> d[i];

    map<int,int> mp;
    for(auto x:d)mp[x]++;

    if(d[0] != 0){
        cout << 0;
        return;
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        ans = (ans * mp[d[i] - 1]) % MOD;
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
