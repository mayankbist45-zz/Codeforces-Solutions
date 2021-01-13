#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

int solve(vector<int> v, int bit) {
    if (bit == -1 or v.empty())return v.size();
    vector<int> a, b;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >> bit & 1)a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    return max((b.empty() ? 0 : 1) + solve(a, bit - 1), (a.empty() ? 0 : 1) + solve(b, bit - 1));
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << n - solve(v, 30) << endl;
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