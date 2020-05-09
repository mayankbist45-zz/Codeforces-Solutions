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

int pref[maxn], suf[maxn];

void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n ;i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)pref[i + 1] = __gcd(v[i], pref[i]); 
    for(int i = n; i > 0; i--)suf[i] = __gcd(v[i - 1], suf[i + 1]); 

    int mx = pref[n];
    for(int i = 1; i <= n; i++){
        if(mx < __gcd(pref[i - 1], suf[i + 1]))
            mx = __gcd(pref[i - 1], suf[i + 1]);
    }
    cout << mx << endl;
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
