#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    map<int, int> mp;
    vector<int> row[10][n + 1], col[10][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[v[i][j] - '0']++;
            row[v[i][j] - '0'][i].push_back(j);
            col[v[i][j] - '0'][j].push_back(i);
        }
    }
    for (int dgt = 0; dgt < 10; dgt++) {
        if (mp[dgt] <= 1) {
            cout << 0 << " ";
            continue;
        }
        int area = 0;
        int mn = LLONG_MAX, mx = 0;
        for (int i = 0; i < n; i++) {
            if (row[dgt][i].empty())continue;
            mx = max(mx, row[dgt][i].back());
            mn = min(mn, row[dgt][i].front());
            area = max(area, (row[dgt][i].front() - row[dgt][i].back()) * i);
            area = max(area, (row[dgt][i].front() - row[dgt][i].back()) * (n - i - 1));
        }
        for (int i = 0; i < n; i++) {
            if (col[dgt][i].empty())continue;
            area = max(area, (n - col[dgt][i].front() - 1) * abs(mx - i));
            area = max(area, (col[dgt][i].back()) * abs(mx - i));
            area = max(area, (n - col[dgt][i].front() - 1) * abs(mn - i));
            area = max(area, (col[dgt][i].back()) * abs(mn - i));
        }
        mn = LLONG_MAX, mx = 0;
        for (int i = 0; i < n; i++) {
            if (col[dgt][i].empty())continue;
            mx = max(mx, col[dgt][i].back());
            mn = min(mn, col[dgt][i].front());
            area = max(area, (col[dgt][i].front() - col[dgt][i].back()) * i);
            area = max(area, (col[dgt][i].front() - col[dgt][i].back()) * (n - i - 1));
        }
        for (int i = 0; i < n; i++) {
            if (row[dgt][i].empty())continue;
            area = max(area, (n - row[dgt][i].front() - 1) *abs( mx - i));
            area = max(area, (row[dgt][i].back()) * abs(mx - i));
            area = max(area, (n - row[dgt][i].front() - 1) * abs(mn - i));
            area = max(area, (row[dgt][i].back()) * abs(mn - i));
        }
        cout << area << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}