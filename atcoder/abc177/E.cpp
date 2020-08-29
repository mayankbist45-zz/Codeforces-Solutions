#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

int dp[maxn];

void solve() {
    for (int i = 2; i <= 1000000; i++)
        for (int j = i; j <= 1000000; j += i)
            if (dp[j] == 0)dp[j] = i;
    int n;
    cin >> n;

    vector<int> v(n);
    int gcd = 0;
    unordered_map<int, int> mp;
    bool fd = false;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        if (gcd == 0)gcd = v[i];
        else gcd = __gcd(v[i], gcd);

        int now = dp[v[i]], cur = v[i];

        if(fd)continue;
        while (cur > 1) {
            while (cur % now == 0)cur /= now;
            if (mp[now] > 0) {
                fd = true;
                break;
            } else mp[now]++;
            now = dp[cur];
        }
    }
    if (!fd)cout << "pairwise coprime";
    else if (gcd == 1)cout << "setwise coprime";
    else cout << "not coprime";
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
