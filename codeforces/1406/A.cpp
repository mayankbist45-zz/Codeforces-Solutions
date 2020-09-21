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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        if (i and v[i] == v[i - 1])b.insert(v[i]);
        else a.insert(v[i]);
    }
    int cur1 = 0, cur2 = 0, ans = 0;
    bool fd1 = false, fd2 = false;
    for (auto x: a) {
        if (x != cur1) {
            ans += cur1;
            fd1 = true;
            break;
        }
        cur1++;
    }
    if(!fd1)ans+= cur1;
    for (auto x: b) {
        if (x != cur2) {
            ans += cur2;
            fd2 = true;
            break;
        }
        cur2++;
    }
    if(!fd2)ans+= cur2;
 
    cout << ans << endl;
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