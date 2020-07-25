#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> prefixFunction(string &s) {
    vector<int> pi(s.size());
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])j = pi[j - 1];
        if (s[i] == s[j])pi[i] = j + 1;
    }
    return pi;
}

void solve() {
    int n;
    cin >> n;

    string ans;
    cin >> ans;

    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;

        int mn = min(s.size(), ans.size());
        string nw = s + '#' + ans.substr((int) ans.size() - mn);
        vector<int> pre = prefixFunction(nw);
        int mx = pre.back();
        ans += s.substr(mx);
    }
    cout << ans << endl;
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