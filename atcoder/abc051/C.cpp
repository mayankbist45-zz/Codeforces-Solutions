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
    int sx, sy ,tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans;
    for(int i = 0; i < tx - sx; i++)ans += 'R';
    for(int i = 0; i < ty - sy; i++)ans += 'U';
    for(int i = 0; i < tx - sx; i++)ans += 'L';
    for(int i = 0; i < ty - sy; i++)ans += 'D';

    ans += 'D';
    for(int i = 0; i < tx - sx + 1; i++)ans += 'R';
    for(int i = 0; i < ty - sy + 1; i++)ans += 'U';
    ans += 'L';
    ans += 'U';
    for(int i = 0; i < tx - sx + 1; i++)ans += 'L';
    for(int i = 0; i < ty - sy + 1; i++)ans += 'D';
    ans += 'R';
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
