#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int ct = 0;
    for (auto x:s) {
        if (x == ')')ct++;
        else break;
    }
    if (ct > n - ct)cout << "Yes";
    else cout << "No";
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