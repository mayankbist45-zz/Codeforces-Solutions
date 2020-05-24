//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 100010
//const int MOD = 1000000007;
//
//int n, m;
//int v[maxn], b[maxn];
//
//int solve(int pos1, int pos2, vector<int> co) {
//    if (pos1 == n and pos2 == m) {
//        for (auto x: co)cout << x << " ";
//        cout << endl;
//        return 1;
//    }
//
//    int ans = 0;
//    if (pos1 < n) {
//        co.push_back(v[pos1]);
//        ans += solve(pos1 + 1, pos2, co);
//        co.pop_back();
//    }
//    if (pos2 < 2) {
//        co.push_back(b[pos2]);
//        ans += solve(pos1, pos2 + 1, co);
//        co.pop_back();
//    }
//    return ans;
//}
//
//void solve() {
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) cin >> v[i];
//    for (int i = 0; i < m; ++i) cin >> b[i];
//    vector<int> co;
//    cout << solve(0, 0, co);
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
    string s;
    cin >> s;

    map<int, int> mp;
    int n = s.size();
    for (auto &x: s)mp[x]++;
    int ans = 0;
    for (auto x: mp)ans += x.second * (x.second - 1) / 2;
    cout << (n * (n - 1) / 2 - ans) + 1 << endl;
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