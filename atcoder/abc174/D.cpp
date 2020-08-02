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

    int ans = 0;
    for (int i = 0, j = n - 1; i < n and i < j;) {
        if (s[i] == 'W' and s[j] == 'R')swap(s[i++], s[j--]), ans++;
        else if (s[j] == 'W')j--;
        else if (s[i] == 'R')i++;
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