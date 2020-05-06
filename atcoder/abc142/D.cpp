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
    int a, b;
    cin >> a >> b;

    int tp = __gcd(a, b);
    vector<int> div;
    for(int i = 1; i * i <= tp; i++){
        if(tp % i == 0){
            div.push_back(i);
            if(tp/i != i)div.push_back(tp/i);
        }
    }
    int ans = 1;
    for(int i = 2; i * i <= tp; i++){
        int ct =0 ;
        while(tp %  i == 0)tp/=i,ct++;
        ans += (ct?1:0);
    }
    if(tp > 1)ans++;
    cout <<ans << endl;
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
