#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

vector<pair<pair<int, int>, pair<int, int>>> g[maxn];

int f[maxn];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({{b, i},
                        {c, 0}});
        g[b].push_back({{a, i},
                        {c, 1}});
        f[a] += c;
        f[b] += c;
    }
    for (int i = 1; i <= n; i++)f[i] /= 2;
    map<pair<int, int>, int> mp;
    queue<int> q;
    q.push(1);
    vector<int> id(m, -1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto x: g[top]) {
            if (id[x.first.second] == -1) {
                id[x.first.second] = x.second.second;
                f[x.first.first] -= x.second.first;
                if (f[x.first.first] == 0 and x.first.first != n)q.push(x.first.first);
            }
        }
    }
    for (auto x: id)cout << x << endl;
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