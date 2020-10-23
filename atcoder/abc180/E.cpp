#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int INF = 1e14;

struct pot {
    int a, b, c;
};
vector<pot> v;
int n;
int getDist(pot a, pot b) {
    return abs(a.a - b.a) + abs(a.b - b.b) + max(0ll, b.c - a.c);
}
int dp[20][1000010];
int solve(int cur, int mask) {
    if (__builtin_popcount(mask) == n) {
        return getDist(v[cur], v[0]);
    }
    int &ans = dp[cur][mask];
    if (ans != -1)return ans;
    ans = INF;
    for (int i = 0; i < n; i++) {
        if (mask >> i & 1)continue;
        ans = min(ans, getDist(v[cur], v[i]) + solve(i, mask | (1 << i)));
    }
    return ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    v = vector<pot>(n);
//    int x, y, z;
//    cin >> x >> y >> z;
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    cout << solve(0, 1) << endl;
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