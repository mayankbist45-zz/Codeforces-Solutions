#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 1010
const int MOD = 1000000007;

int a[maxn][maxn];

void solve() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    priority_queue<int> row, col;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        row.push(sum);
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += a[j][i];
        col.push(sum);
    }
    vector<int> x, y;
    for (int i = 0; i < k; i++) {
        x.push_back(row.top());
        row.push(row.top() - m * p);
        row.pop();

        y.push_back(col.top());
        col.push(col.top() - n * p);
        col.pop();
    }
    partial_sum(x.begin(), x.end(), x.begin());
    partial_sum(y.begin(), y.end(), y.begin());
    int ans = max(x.back(), y.back());
    for (int i = 0; i <= k; i++) {
        int cur = 0;
        if (i)cur += x[i - 1];
        if (k - i)cur += y[k - i - 1];
        ans = max(ans, cur - i * (k - i) * p);
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