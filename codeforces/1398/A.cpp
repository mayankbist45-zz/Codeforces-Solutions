//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 210
//const int MOD = 1000000007;
//
//int dp[maxn][maxn][maxn];
//void solve() {
//    int r, g, b;
//    cin >> r >> g >> b;
//
//    vector<int> R(r), G(g), B(b);
//    for (int i = 0; i < r; i++)cin >> R[i];
//    for (int i = 0; i < g; i++)cin >> G[i];
//    for (int i = 0; i < b; i++)cin >> B[i];
//
//    sort(R.rbegin(), R.rend());
//    sort(G.rbegin(), G.rend());
//    sort(B.rbegin(), B.rend());
//
//    
//}
//
//int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t = 1;
////    cin >> t;
//
//    while (t--)
//        solve();
//    return 0;
//}

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
    if (v[0] + v[1] <= v.back())cout << 1 << " " << 2 << " " << v.size();
    else cout << -1;
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