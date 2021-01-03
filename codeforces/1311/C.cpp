#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> v(m), val(n + 10);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
        v[i]--;
        val[v[i]]++;
    }
    val[n - 1]++;
    map<char, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        val[i] += val[i + 1];
        mp[s[i]] += val[i];
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
        cout << mp[ch] << " ";
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