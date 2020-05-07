#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 30010
const int MOD = 1000000007;

bool dp[maxn][4][1000];
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    dp[0][0][0] = true;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j <= 3; j++){
            for(int k = 0; k < 1000; k++){
                if(dp[i][j][k] == false)continue;

                dp[i + 1][j][k] = true;
                if(j <= 2)
                    dp[i + 1][j + 1][k * 10 + (s[i] - '0')] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++)
        ans += dp[n][3][i];
    cout << ans;
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
