#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i) + s.substr(0, i) == t){
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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