#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

int digit(int n){
    int dig = 0;
    while(n > 0){
        dig++;
        n /= 10;
    }
    return dig;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int odd = 0;
    for (int i = 1; i <= n; i++)
        if (digit(i) & 1)
            odd++;
    cout << odd << endl;

    return 0;
}