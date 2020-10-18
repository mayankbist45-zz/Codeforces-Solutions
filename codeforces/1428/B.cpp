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

    map<char, int> mp;
    for (auto x: s)mp[x]++;
    int ct = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' or s[(i - 1 + n) % n] == '-')ct++;
        else if (s[i] == '>' and mp['>'] + mp['-'] == n)ct++;
        else if (s[i] == '<' and mp['<'] + mp['-'] == n)ct++;
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