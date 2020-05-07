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
    int h, w;
    cin >> h >> w;

    int n;
    cin >> n;

    vector<int>v(n);
    
    int ct = 0;
    int mat[h][w];

    bool rit = true;
    int cur = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        for(int j = 0; j < v[i]; j++){
            if(rit){
                mat[cur][ct] = i + 1;
                ct++;
                if(ct == w){
                    cur++;
                    ct--;
                    rit = false;
                }
            }
            else {
                mat[cur][ct] = i + 1;
                ct--;
                if(ct == -1){
                    ct++;
                    cur++;
                    rit = true;
                }
            }
         
        }
    }
    for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)cout << mat[i][j] << " \n"[j + 1 == w];
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
