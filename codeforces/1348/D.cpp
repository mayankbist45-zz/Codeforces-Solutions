#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v = {1};
    n--;
    while (n > 0 and v.back() * 2 <= n) {
        n -= v.back() * 2;
        v.push_back(v.back() * 2);
    }
    if (n)
        v.push_back(n);
    sort(v.begin(), v.end());

    cout << v.size() - 1 << endl;
    for (int i = 1; i < v.size(); i++)cout << v[i] - v[i - 1] << " ";
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