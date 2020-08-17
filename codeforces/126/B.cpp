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
    string s;
    cin >> s;

    vector<int> pre = prefixFunction(s);
    int lst = pre.back();

    map<int, int> mp;
    for (auto x: pre)mp[x]++;
    mp[pre.back()]--;
    int ct = 0, cur = pre.back();
    while (cur) {
        ct += mp[cur];
        if (ct) {
            cout << s.substr(0, cur) << endl;
            return;
        }
        cur = pre[cur - 1];
    }
    cout << "Just a legend" << endl;
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