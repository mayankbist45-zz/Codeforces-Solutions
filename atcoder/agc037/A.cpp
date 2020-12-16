#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int ct = 0;
    vector<int> v(26, 1);
    int pre = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i and s[i - 1] == s[i] and pre == 1) {
            if (i + 1 < s.size())ct++, i++, pre = 2;
        } else ct++, pre = 1;
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