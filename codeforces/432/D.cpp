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
    int n = s.size();
    vector<int> pre = prefixFunction(s);
    vector<int> len(n + 1, 1);
    for (int i = n; i > 0; i--)len[pre[i - 1]] += len[i];
    vector<pair<int, int>> ans;
    for(int i = n; i > 0; i = pre[i - 1])ans.push_back({i, len[i]});
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x: ans)cout << x.first << " " << x.second << endl;
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