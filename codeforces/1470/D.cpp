#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 300010
const int MOD = 1000000007;

vector<int> g[maxn];
vector<int> white;
int clr[maxn], push[maxn];

void solve() {
    int n, m;
    cin >> n >> m;

    white.clear();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        push[i] = false;
        clr[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ct = 0;

    queue<int> q;
    q.push(1);
    clr[1] = 1;
    push[1] = 1;
    vector<int> choose;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (clr[node] == -1)clr[node] = 1;
        if (clr[node] == 1)
            white.push_back(node);
        for (auto x: g[node]) {
            if (clr[x] == -1) {
                if (!push[x])
                    q.push(x), push[x] = 1;
                if (clr[node] == 1)clr[x] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (push[i])continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << white.size() << endl;
    for (auto x: white)cout << x << " ";
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