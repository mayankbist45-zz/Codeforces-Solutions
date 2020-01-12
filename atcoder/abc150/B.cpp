#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s.substr(i, 3) == "ABC")
            ans++;
    }
    cout << ans;
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