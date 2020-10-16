#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    string make;
    int ct = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A')ct++;
        else {
            if (ct)ct--;
            else ct++;
        }
    }
    cout << ct << endl;
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