#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int even = 0, odd = 0;
    map<int, int> ev, od;
    for (int i = 0; i < s.size(); i++) {
        odd++;
        if (i & 1) {
            even += ev[s[i]];
            odd += od[s[i]];
        } else {
            odd += ev[s[i]];
            even += od[s[i]];
        }

        if (i & 1)od[s[i]]++;
        else ev[s[i]]++;
    }
    cout << even << " " << odd << endl;
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