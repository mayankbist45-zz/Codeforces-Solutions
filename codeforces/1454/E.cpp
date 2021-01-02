#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

set<int> g[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1)
            q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        cnt[*g[top].begin()] += cnt[top];
        g[*g[top].begin()].erase(top);
        cnt[top] = 0;

        if (g[*g[top].begin()].size() == 1)
            q.push(*g[top].begin());
    }

    for(int i = 1; i <= n; i++){
        int val = cnt[i];
        ans += val * (val - 1);
        ans += 2 * (n - val) * val;
    }
    cout << ans / 2 << endl;
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