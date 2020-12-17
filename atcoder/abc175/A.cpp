#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int mx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            int j = i;
            while (j + 1 < s.size() and s[j + 1] == 'R')j++;
            mx = max(mx, j - i + 1);
            i = j;
        }
    }
    cout << mx;
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