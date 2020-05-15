#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 10000010
const int MOD = 1000000007;
using int32 = __uint32_t;

int pre[maxn];
void solve() {
    int n;
    cin >> n;

    int ct = 1;
    int sum = 0;

    while(sum <= n)sum += ct,ct++;
    for(int i = 1; i < ct; i++){
        if(sum - n == i)continue;
        cout << i <<endl;
    }
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
