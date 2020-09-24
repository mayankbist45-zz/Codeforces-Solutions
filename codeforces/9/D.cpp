#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

/*
 * no of trees of height h with n nodes
 * first choose someone as root
 * lets say we choose x as root
 * then x - 1 will go to left side and n - x will go to right of bst
 * then dp[n][h] = dp[x - 1][h - 1] * dp[n - x][h - 1] for all x from 1 to n
 *
 * okk one them should produce h - 1 height but it is not necessary for
 * both to probduce h - 1 height so this approach seems wrong
 *
 * how about trying out all combinations of height they give while going
 * inside recursion like (x, h - 1) and (h - 1, x)
 *
 */
int dp[40][40];
int solve(int n, int h) {
    //some base cases should come here
    if (n == 0)return h == 0;
    if (h == 0)return 0;

    int &ans = dp[n][h];
    if (ans != -1)return ans;
    ans = 0;
    //lets choose root
    for (int i = 1; i <= n; i++) {
        for (int ht = 0; ht < h - 1; ht++)
            ans += solve(i - 1, ht) * solve(n - i, h - 1) + solve(i - 1, h - 1) * solve(n - i, ht);
        ans += solve(i - 1, h - 1) * solve(n - i, h - 1);
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, h;
    cin >> n >> h;

    solve(n, n);
    int ans = 0;
    for (int i = h; i <= n; i++)ans += solve(n, i);
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