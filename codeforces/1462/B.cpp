#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string tp = "2020";
    for (int i = 0; i <= 4; i++) {
//        cout << s.substr(0, i) + s.substr(n - (4 - i)) << endl;
        if(s.substr(0, i) + s.substr(n - (4 - i)) == tp){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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