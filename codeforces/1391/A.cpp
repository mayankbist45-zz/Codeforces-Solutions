#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
void solve() {
    int n;
    cin >> n;
 
    for (int i = n; i > 0; i--) {
        cout << i << " ";
    }
    cout << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
 
    while (t--)
        solve();
    return 0;
}