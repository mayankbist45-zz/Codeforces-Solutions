//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 100010
//const int MOD = 1000000007;
//
//void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> v(n), b(n);
//    for (int i = 0; i < n; ++i)cin >> v[i];
//    for (int i = 0; i < n; ++i)cin >> b[i];
//    sort(v.begin(), v.end());
//    sort(b.begin(), b.end());
//
//    int va = accumulate(v.begin(), v.end(), 0ll);
//    int vb = accumulate(b.begin(), b.end(), 0ll);
//    if (va > vb) {
//        cout << "No" << endl;
//        return;
//    } else {
//
//    }
//    for (int i = 0; i < n; i++) {
//        if (v[i] == b[i])continue;
//        else if (v[i] > b[i]) {
//            cout << "No" << endl;
//            return;
//        }
//    }
//    cout << "Yes" << endl;
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

    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), 0ll);
    for (int i = 0; i <= n; i++) {
        for (int j = 6; j + i <= n; j *= 6)
            dp[j + i] = min(dp[j + i], 1 + dp[i]);
        for (int j = 9; j + i <= n; j *= 9)
            dp[j + i] = min(dp[j + i], 1 + dp[i]);
    }
    cout << dp[n] << endl;
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