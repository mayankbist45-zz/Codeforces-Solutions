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

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> v;
    for(int i = 0, tp; i < n; i++)cin >> tp, v.insert(tp);

    vector<pair<int,int>> q(m);
    for(int i = 0; i < m; i++)cin >> q[i].first >> q[i].second;
    sort(q.begin(), q.end(), [](pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    });
    for(int i = 0; i < m;i++){
        int ct = q[i].first;
        while(ct-- and *v.begin() < q[i].second){
            v.erase(v.begin());
            v.insert(q[i].second);
        }
        if(ct == q[i].first)break;
    }
    int64_t ans = 0;
    for(auto x: v){
        ans += x;
        // cout << x << endl;
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
