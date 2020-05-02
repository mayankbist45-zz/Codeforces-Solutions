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

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int sum = 0, id = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (i + 1 < n and 2 * sum < v[i + 1])
            id = i + 1;
    }
    cout << n - id << endl;
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