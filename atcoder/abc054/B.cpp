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
    int n,m;
    cin >> n >> m;

    vector<string> v(n), b(m);
    for(int i = 0; i < n; i++)cin >> v[i];
    for(int i = 0; i < m; i++)cin >> b[i];

    for(int i = 0; i + m - 1< n; i++){
        for(int j = 0; j + m - 1< n; j++){
            bool fl = true;
            for(int k = i; k < i + m; k++){
                for(int l = j; l < j + m; l++){
                    if(v[k][l] != b[k - i][l- j])fl = false;
                }
            }
            if(fl){
                cout << "Yes";
                return ;
            }
        }
    }
    cout << "No";
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
