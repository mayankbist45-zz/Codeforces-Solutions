#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define um unordered_map
#define us unordered_set
#define mod 1000000007
#define MAXN 100005
#define all(x) x.begin(),x.end()

using namespace std;

void bruh() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(2, vector<int>(n, 0));
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
        if (i and a[i] > a[i - 1]) {
            dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
        }
        if (i > 1 and a[i] > a[i - 2])
            dp[1][i] = max(dp[1][i], dp[0][i - 2] + 1);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)mx = max({mx, dp[0][i], dp[1][i]});
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
//	cin>>t;
    while (t--) {
        bruh();
    }
    return 0;
}
