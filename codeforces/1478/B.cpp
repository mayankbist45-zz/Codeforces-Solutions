//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define int long long
//#define endl '\n'
//#define maxn 200010
//const int MOD = 1000000007;
//
//void solve() {
//    int n;
//    cin >> n;
//
//    n *= 2;
//
//    vector<int> v(n);
//    map<int, int> mp;
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i];
//        mp[v[i]]++;
//    }
//    for (auto x: mp) {
//        if (x.second & 1) {
//            cout << "No" << endl;
//            return;
//        }
//    }
//
//    // try to construct one
//    int sum = accumulate(v.begin(), v.end(), 0ll);
//    if (sum % 4 == 0)cout << "YES";
//    else cout << "NO";
//    cout << endl;
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

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

bool canDo(const string &s, int id, int carry) {
    if (id < 0)return carry == 0;
    for (; id >= 0 and carry; id--) {
        int now = s[id] - '0';
        if (carry <= now)return true;
        else carry = (carry + 10) / 10;
    }
    return carry == 0;
}
int q, d;

bool contains(int val) {
    string s = to_string(val);
    for (auto x: s) {
        if (x - '0' == d)
            return true;
    }
    return false;
}

void solve() {
    cin >> q >> d;
    vector<int> cur;
    vector<int> dp(10 * d + 10);
    int val = 10 * d + 3;
    for (int j = 1; j + 1 <= val; j++) {
        if (contains(j)) {
            dp[j] = 1;
            cur.push_back(j);
            for (auto x: cur) {
                for (int k = j + x; k <= val; k += x)
                    dp[k]++;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int val = i;
        cin >> val;

        if (val <= 10 * d) {
            if (dp[val])cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "YES" << endl;
    }
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