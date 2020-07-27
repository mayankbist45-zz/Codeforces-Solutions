#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> primes;
int msk[70];

void pro() {
    for (int i = 2; i <= 60; i++) {
        int cur = i, pr = 1;
        for (int j = 2; j * j <= cur; j++)if (cur % j == 0)pr = 0;
        if (pr)primes.push_back(cur);
    }
    for (int i = 2; i <= 60; i++) {
        int val = 0;
        for (int j = 0; j < primes.size(); j++) {
            int x = primes[j];
            if (i % x == 0) {
                val |= (1 << j);
            }
        }
        msk[i] = val;
    }
}

int n;
vector<int> v;
int dp[110][(1 << 18)];

int solve(int pos, int mask) {
    if (pos == n)return 0;
    int &ans = dp[pos][mask];
    if (ans != -1)return ans;
    ans = abs(v[pos] - 1) + solve(pos + 1, mask);
    for (int i = 2; i <= 60; i++) {
        if (mask & msk[i])continue;
        ans = min(ans, abs(i - v[pos]) + solve(pos + 1, mask | msk[i]));
    }
    return ans;
}

vector<int> ans;

bool backT(int pos, int mask, int sol) {
    if (pos == n and sol == 0)return true;
    if (pos == n or sol != dp[pos][mask])return false;
    if (backT(pos + 1, mask, sol - v[pos] + 1)) {
        ans.push_back(1);
        return true;
    }
    for (int i = 2; i <= 60; i++) {
        if (mask & msk[i])continue;
        if (backT(pos + 1, mask | msk[i], sol - abs(v[pos] - i))) {
            ans.push_back(i);
            return 1;
        }
    }
    return 0;
}

void solve() {
    memset(dp, -1, sizeof dp);
    pro();
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    backT(0, 0, solve(0, 0));
    reverse(ans.begin(), ans.end());
    for (auto x: ans)cout << x << " ";
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