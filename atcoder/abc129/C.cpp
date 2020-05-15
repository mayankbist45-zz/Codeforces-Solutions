#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
using int32 = __uint32_t;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        int tp;
        cin >> tp;
        vis[tp] = true;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (i + 1 <= n)
            dp[i + 1] += dp[i];
        if (i + 2 <= n)
            dp[i + 2] += dp[i];
        if (i + 1 <= n)

            dp[i + 1] %= MOD;
        if (i + 2 <= n)

            dp[i + 2] %= MOD;
    }
    cout << dp[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //    cin >> t;

    while (t--)
        solve();
    return 0;
}
