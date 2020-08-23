#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 10000010
const int MOD = 1000000007;

int dp[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0, cur; i < n; ++i) {
        cin >> cur;
        int now = dp[cur], init = cur;

        while (cur % now == 0)cur /= now;
        if (cur != 1 and init / cur != 1)a.push_back(cur), b.push_back(init / cur);
        else a.push_back(-1), b.push_back(-1);
    }
    for (auto x: a)cout << x << " ";
    cout << endl;
    for (auto x: b)cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= 10000000; i++)
        for (int j = i; j <= 10000000; j += i)
            if (dp[j] == 0)dp[j] = i;

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}