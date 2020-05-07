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
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        int ct= 0;
        for(int j = i; j <= i + 3 - 1 and j < s.size(); j++){
            if(s[i] == s[j])ct++;
        }
        if(ct == 3){
            cout << "Yes";
            return;
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
