#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

struct pot {
    int s, t, c;
};
int ans[maxn], range[maxn];

void solve() {
    int n, c;
    cin >> n >> c;

    vector<pot> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].s >> v[i].t >> v[i].c;

    for (int i = 1; i <= 30; i++) {
        memset(range, 0, sizeof range);
        for (auto x: v)
            if (x.c == i) {
                range[2 * x.s - 1] += 1;
                range[2 * x.t] -= 1;
            }
        partial_sum(range, range + maxn, range);
        for (int i = 0; i < maxn; i++)
            if (range[i])ans[i]++;
    }
    cout << *max_element(ans, ans + maxn) << endl;
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