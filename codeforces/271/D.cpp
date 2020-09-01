#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string a, b;
    cin >> a >> b;

    int k;
    cin >> k;

    set<int> hash[1501];
    for (int i = 0; i < a.size(); i++) {
        int ct = 0, val = 1;
        for (int j = i; j < a.size(); j++) {
            ct += b[a[j] - 'a'] == '0';
            if (ct > k)break;
            val = val * 117 + a[j];
            hash[j - i + 1].insert(val);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1500; i++) {
        ans += hash[i].size();
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