#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int vis[maxn];

int getDiv(int a, int p, int cur) {
    int ans = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (!vis[i]) ans++;
            else if (vis[i] < p)ans++;
            vis[i] = cur;
            if (a / i != i) {
                if (!vis[a / i])ans++;
                else if (vis[a / i] < p)ans++;
                vis[a / i] = cur;
            }
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << getDiv(a, i - b, i) << endl;
    }
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