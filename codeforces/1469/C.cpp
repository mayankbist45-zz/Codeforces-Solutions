#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (auto &x : h)cin >> x;

    int mn = h[0], mx = h[0];
    for (int i = 1; i < h.size(); ++i) {
        int curmn = h[i], curmx = h[i] + (i + 1 == h.size() ? 0 : k - 1);
        mn = max(mn + 1 - k, curmn);
        mx = min(mx + k - 1, curmx);
        if(mx < mn){
            cout << "NO" << endl;
            return;
        }
    }
    if (mn <= mx)cout << "YES" << endl;
    else cout << "NO" << endl;
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