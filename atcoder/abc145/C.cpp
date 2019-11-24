#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int f[11];

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= 10; i++)
        f[i] = i * f[i - 1];
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> vx(n);
    double ans = 0;
    iota(vx.begin(), vx.end(), 0);
    do {
        for (int i = 1; i < n; i++) {
            ans += dist(v[vx[i]], v[vx[i - 1]]);
        }
    } while (next_permutation(vx.begin(), vx.end()));
    ans = ans / f[n];
    cout << fixed << setprecision(10) << ans << endl;
}