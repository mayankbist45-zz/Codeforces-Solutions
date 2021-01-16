#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 10000010
const int MOD = 1000000007;

int mp[maxn];
void solve() {
    int n;
    cin >> n;

    pair<int, int> ans;
    int mn = LLONG_MAX, mx = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (mp[v[i]] and mn > v[i]) {
            ans = {mp[v[i]], i + 1};
            mn = v[i];
        }
        mp[v[i]] = i + 1;
        mx = max(mx, v[i]);
    }
    for (int i = 1; i <= mx; i++) {
        pair<int, int> cur = {-1, -1};
        for (int now = i; now <= mx; now += i) {
            if (mp[now]) {
                if (cur.first == -1)cur.first = mp[now];
                else {
                    cur.second = mp[now];
                    break;
                }
            }
        }
        if (cur.second == -1)continue;
        int val = v[cur.first - 1] * v[cur.second - 1] / __gcd(v[cur.first - 1], v[cur.second - 1]);
        if (val < mn) {
            mn = val;
            ans = cur;
        }
    }
    if (ans.first > ans.second)swap(ans.first, ans.second);
    cout << ans.first << " " << ans.second << endl;
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