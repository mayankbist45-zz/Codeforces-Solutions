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
    string a, b;
    cin >> a >> b;

    map<char,char> x, y;
    bool ans = true;
    for(int i = 0 ;i < a.size(); i++){
        if(x.count(a[i]) and x[a[i]] != b[i])ans = false;
        if(y.count(b[i]) and y[b[i]] != a[i])ans = false;
        x[a[i]] = b[i];
        y[b[i]] = a[i];
    }
    if(ans)cout << "Yes";
    else cout << "No";
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
