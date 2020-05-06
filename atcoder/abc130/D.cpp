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

int n, k;
void solve() {
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    auto gett = [](int val, vector<int> &pref) -> int{
        if(val < -1)
        return -1;
        int lo = 0 , hi = n, mid, ans = -1;
        while(lo <= hi){
            mid = lo + hi >> 1;
            if(pref[mid] <= val){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    };

    int ans = 0;
    vector<int> pref(n + 1);
    for(int i = 0; i < n; i++)pref[i + 1] = pref[i] + v[i];
    for(int i = 1; i <= n; i++){
        int tp = pref[i] - k;
        int id = gett(tp, pref);
        if(id == -1)continue;
        ans += id + 1;
    }
    cout << ans;
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
