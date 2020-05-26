#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    //Max can be a star graph obviously
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; i++)edges.emplace_back(1, i);
    int net = (n - 1) * (n - 2) / 2 - k;
    if (net < 0) {
        cout << -1 << endl;
        return;
    }
    int cur = 2, ele = 3;
    while (cur <= n and net) {
        edges.push_back({cur, ele});
        ele++;
        if (ele == n + 1)
            cur++, ele = cur + 1;
        net--;
    }
    cout << edges.size() << endl;
    for(auto x: edges)cout << x.first << " " << x.second << endl;
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