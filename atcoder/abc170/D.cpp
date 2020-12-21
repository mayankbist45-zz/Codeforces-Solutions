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
//    int n, s, k;
//    cin >> n >> s >> k;
//
//
//}
//
//int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t = 1;
//    cin >> t;
//
//    while (t--)
//        solve();
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int ct = 0;
    for (auto x :v) {
        mp[x]--;
        bool fd = true;
        for (int i = 1; i * i <= x; i++) {
            if (x % i)continue;
            if (mp[i] > 0) {
                fd = false;
                break;
            }
            if (mp[x / i] > 0) {
                fd = false;
                break;
            }
        }
        ct += fd;
        mp[x]++;
    }
    cout << ct << endl;
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