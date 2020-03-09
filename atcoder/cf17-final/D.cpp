//Exchange Arguments
//1.Boxes
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

int dp[5010][5010];

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    memset(dp, 63, sizeof dp);
    int inf = dp[0][0];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j > 0 and dp[i - 1][j - 1] != inf and dp[i - 1][j - 1] <= v[i - 1].first)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + v[i - 1].second);
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == inf)continue;
            ans = max(ans, j);
        }
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