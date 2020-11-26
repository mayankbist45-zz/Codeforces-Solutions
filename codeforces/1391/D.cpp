#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define maxn 1000010
const int MOD = 1000000007;

int n, m;
vector<string> v;
int dp[maxn][10];
int solve(int pos, int mask) {
    if (pos == n) {
        return 0;
    }
    int &ans = dp[pos][mask];
    if(ans != -1)return ans;
    ans = INT_MAX;
    if (pos == 0) {
        for (int cur = 0; cur < (1 << m); cur++) {
            int ct = 0;
            for (int j = 0; j < m; j++)
                ct += (v[pos][j] - '0') != (cur >> j & 1);
            ans = min(ans, ct + solve(pos + 1, cur));
        }
    } else {
        for (int cur = 0; cur < (1 << m); cur++) {
            int ct = 0;
            for (int j = 0; j < m; j++)
                ct += (v[pos][j] - '0') != (cur >> j & 1);
            bool good = true;
            for (int j = 1; j < m; j++) {
                int add = (cur >> j & 1) + (cur >> (j - 1) & 1);
                add += (mask >> j & 1) + (mask >> (j - 1) & 1);
                if (add & 1)continue;
                good = false;
                break;
            }
            if (good)ans = min(ans, ct + solve(pos + 1, cur));
        }
    }
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    v = vector<string>(n);
    for (auto &x: v)cin >> x;
    if (min(n, m) > 3) {
        cout << -1 << endl;
        return;
    }
    if (n < m) {
        vector<string> temp;
        for (int i = 0; i < m; i++) {
            string s;
            for (int j = 0; j < n; j++) s += v[j][i];
            temp.push_back(s);
        }
        v = temp;
        swap(n, m);
    }
    cout << solve(0, 0) << endl;
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