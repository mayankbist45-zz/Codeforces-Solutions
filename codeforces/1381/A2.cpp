#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    vector<int> v1, v2;
    for (int i = 1; i < n; i++)if (a[i] != a[i - 1])v1.push_back(i - 1);
    for (int i = 1; i < n; i++)if (b[i] != b[i - 1])v2.push_back(i - 1);
    if (a.back() != b.back())v1.push_back(n - 1);
    cout << v1.size() + v2.size() << " ";
    for (auto x: v1)cout << x + 1 << " ";
    reverse(v2.begin(), v2.end());
    for (auto x: v2)cout << x + 1 << " ";
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