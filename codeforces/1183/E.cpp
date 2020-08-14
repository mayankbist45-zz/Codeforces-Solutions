#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int n, k, ans = 0;

void bfs(string src) {
    map<string, bool> mp;
    queue<string> q;
    q.push(src);
    mp[src] = true;

    while (!q.empty()) {
        string node = q.front();
        q.pop();
//        cout << node << " ";
        for (int i = 0; i < node.size(); i++) {
            string nw = node.substr(0, i) + node.substr(i + 1);
            if (!mp.count(nw))mp[nw] = 1, q.push(nw);
        }
        ans += n - node.size();
        k--;
        if (k == 0)return;
    }
}

void solve() {
    cin >> n >> k;

    string s;
    cin >> s;

    bfs(s);
    if (k)cout << -1 << endl;
    else cout << ans << endl;
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