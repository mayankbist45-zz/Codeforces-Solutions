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
    string a, b;
    cin >> a >> b;

    string tp = b + '&' + a;
    vector<int> cur = prefixFunction(tp);
    vector<int> v;
    v.push_back(0);
    for (int i = b.size() + 1; i < cur.size(); i++)v.push_back(cur[i]);

    vector<int> pref1(a.size() + 1), pref2(a.size() + 1), dp(a.size() + 1);

    int val = b.size();
    for (int i = 1; i <= a.size(); i++) {
        if (v[i] != val) dp[i] = dp[i - 1];
        else dp[i] = ((i - (int) b.size() + 1) + pref2[i - b.size()]) % MOD;
        (pref1[i] += pref1[i - 1] + dp[i]) %= MOD;
        (pref2[i] += pref2[i - 1] + pref1[i]) %= MOD;
    }
    int ans = 0;
    for (auto x: dp) {
        ans += x;
        if (ans >= MOD)ans -= MOD;
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