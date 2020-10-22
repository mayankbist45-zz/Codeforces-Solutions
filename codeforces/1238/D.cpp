#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int doit(string &s, int add) {
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n and s[j + 1] != s[i])j++;
        if (i == j)continue;
        int val = j - i - add;
        ans -= val;
        i = max(i, j - 1);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n * (n - 1) / 2;
    ans += doit(s, 0);
    reverse(s.begin(), s.end());
    ans += doit(s, 1);
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