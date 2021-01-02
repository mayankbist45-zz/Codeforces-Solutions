#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    map<string, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.front() == '!')mp[s.substr(1)].second = 1;
        else mp[s].first = 1;
    }
    for (auto x:mp) {
        if (x.second.first + x.second.second == 2) {
            cout << x.first;
            return;
        }
    }
    cout << "satisfiable";
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