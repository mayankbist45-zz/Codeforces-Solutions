#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b ,c;
    cin >> a >> b >> c;
    a = a - b;
    if(c - a <= 0)
        cout << 0 << endl;
    else
        cout << c - a << endl;

    return 0;
}