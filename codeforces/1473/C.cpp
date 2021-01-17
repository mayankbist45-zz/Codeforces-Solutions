#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    int inv = n - k;
    if (inv == 0)for (int i = 1; i <= k; i++)cout << i << " ";
    else {
        vector<int> ans(k);
        for (int i = 0; i < k - inv - 1; i++)ans[i] = i + 1;
        int id = k;
        for (int i = k - inv - 1; i < k; i++) {
            ans[i] = id--;
        }
        for (auto x: ans)cout << x << " ";
    }
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