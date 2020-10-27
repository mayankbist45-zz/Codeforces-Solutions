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
    int ans = 0, ans2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            int j = i;
            while (j + 1 < s.size() and s[j + 1] == '1')j++;
            ans += j - i;
            i = j;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            int j = i;
            while (j + 1 < s.size() and s[j + 1] == '0')j++;
            ans2 += j - i;
            i = j;
        }
    }
    cout << max(ans, ans2) << endl;
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