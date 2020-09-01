#include <bits/stdc++.h>

using namespace std;

#define int long long
#define maxn 100010
const int MOD = 1000000007;

int in[maxn];
set<int> g[maxn];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        in[a]++;
        in[b]++;
        g[a].insert(b);
        g[b].insert(a);
    }

    set<int> v;
    for (int i = 1; i <= n; i++)if (in[i] <= 1)v.insert(i);
    while (v.size() > 1) {
        int u = *v.begin();
        v.erase(v.begin());
        int w = *v.begin();
        v.erase(v.begin());


        int node;
        cout << "? " << u << " " << w << endl;
        cin >> node;

        if (node == u or node == w) {
            cout << "! " << node << endl;
            return;
        }
        if (in[u] == 1) {
            g[*g[u].begin()].erase(u);
            if (--in[*g[u].begin()] <= 1)
                v.insert(*g[u].begin());

        }
        if (in[w] == 1) {
            g[*g[w].begin()].erase(w);
            if (--in[*g[w].begin()] <= 1)
                v.insert(*g[w].begin());
        }
    }
    cout << "! " << *v.begin() << endl;
}

int32_t main() {
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}