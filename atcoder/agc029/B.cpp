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
    int n;
    cin >> n;

    multiset<int> st;    
    for (int i = 0, tp; i < n; i++) {
        cin >> tp;
        st.insert(tp);
    }
    int ans = 0;
    for(int i = 0; i < n and st.size(); i++){
        int tp = *(--st.end());
        st.erase(--st.end());
        for(int j = 0; j < 32; j++){
            if(st.find((1ll << j) - tp) != st.end()){
                ans++;
                st.erase(st.find((1ll<<j) - tp));
                break;
            }
        }
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
