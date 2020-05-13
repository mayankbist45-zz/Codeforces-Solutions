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

int check(int a, int n){
    if(a == 1)return 0;
    int zp = floor(n/(a - 1)) * a;
    if(zp == n)return a - 1;
    return 0;
}

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i* i <= n; i++){
        if(n % i == 0){
            ans += check(i, n);
            if(n/i != i)ans  += check(n/i, n);
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
