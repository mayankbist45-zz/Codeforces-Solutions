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
    int n;
    cin >> n;

    auto get = [](int a,int b)->int{
        return max(to_string(a).size(), to_string(b).size());
    };

    int mn = LLONG_MAX;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            mn = min(mn, get(i, n/i));
        }
    }
    cout << mn << endl;
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
