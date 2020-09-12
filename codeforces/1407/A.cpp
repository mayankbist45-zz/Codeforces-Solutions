#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> v(n);
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ct += v[i] == 1;
    }

    if (ct > n / 2) {
        cout << n / 2 + (n / 2 & 1) << endl;
        for (int i = 1; i <= n / 2; i++)cout << 1 << " ";
        if (n / 2 & 1)cout << 1;
    } else {
        cout << n / 2  << endl;
        for (int i = 1; i <= n / 2; i++)cout << 0 << " ";
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