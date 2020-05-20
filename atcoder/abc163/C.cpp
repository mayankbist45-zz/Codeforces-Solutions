#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<int> g[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        g[v[i]].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++)cout << g[i].size() << endl;
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