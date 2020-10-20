#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    bool fd = false;
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            int j = i;
            while (j + 1 < n and v[j + 1] == 0)j++;
            if (j + 1 == n or v[j + 1] != 1)break;
            ct += j - i;
            i = j;
        }
    }
    cout << ct << endl;
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