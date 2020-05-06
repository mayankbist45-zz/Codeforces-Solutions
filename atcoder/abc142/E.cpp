#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010  
const int MOD = 1000000007;
using int32 = __uint32_t;

int n, m;
vector<pair<int,int>> v;
int dp[maxn][5010];

int solve(int pos, int mask){
    if(__builtin_popcount(mask) == n){
        return 0;
    }
    else if(pos == m){
        return 1e10;
    }

    int &ans = dp[pos][mask];
    if(ans != -1)return ans;
    ans = 1e10;
    ans = min(ans, solve(pos + 1, mask));
    ans = min(ans, v[pos].first + solve(pos + 1, mask | v[pos].second));
    return ans;
}

void solve() {
    memset(dp, -1,sizeof dp);
    cin >> n >> m;

    v = vector<pair<int,int>>(m);
    for(int i = 0; i < m; i++){
        cin >> v[i].first;
        int key;
        cin >> key;
        
        int push = 0;
        for(int i = 0; i < key ;i++){
            int tp;
            cin >> tp;

            tp--;
            for(int i = 0; i <= 14; i++){
                if(tp == i){
                    push = push | (1 << i);
                    break;
                }
            }
        }
        v[i].second = push;
    }
    int ans = solve(0 , 0);
    if(ans >= 1e10)ans = -1;
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
