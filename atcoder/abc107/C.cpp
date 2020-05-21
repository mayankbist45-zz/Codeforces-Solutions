#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, t;

int solve(vector<int> &l, vector<int> &r) {
    int ans = LLONG_MAX;
    for (int i = 0; i < r.size(); i++) {
        if (i + 1 > t)continue;
        if (i + 1 == t)ans = min(ans, r[i]);
        int xtra = t - (i + 1);
        if(xtra == 0)continue;

        if (xtra <= l.size()) {
            ans = min(ans, 2 * r[i] + l[xtra - 1]);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> t;

    vector<int> neg, pos;
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp < 0)neg.push_back(-tp);
        else pos.push_back(tp);
    }
    sort(neg.begin(), neg.end());
    int ans = min(solve(neg, pos), solve(pos, neg));
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