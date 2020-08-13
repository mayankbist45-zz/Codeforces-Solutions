#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define maxn 210
const int MOD = 1000000007;
 
int v[maxn], b[maxn];
int n, m;
 
int ans = INT_MAX;
 
void solve() {
    cin >> n >> m;
 
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
 
    for (int bit = 0; bit < (1 << 9); bit++) {
        bool can = true;
 
        for (int i = 0; i < n; i++) {
            bool fd = false;
            for (int j = 0; j < m; j++) {
                bool mt = true;
                int tp = v[i] & b[j];
                for (int id = 10; id >= 0; id--) {
                    if (bit >> id & 1)continue;
                    if (tp >> id & 1)mt = false;
                }
                if (mt)fd = true;
            }
            if (!fd) {
                can = false;
                break;
            }
        }
 
        if (can) {
            cout << bit << endl;
            return;
        }
    }
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
