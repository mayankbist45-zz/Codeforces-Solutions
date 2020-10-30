#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    string s = to_string(n);
    for (auto x: s) {
        sum += x - '0';
    }
    if(n % sum == 0)cout << "Yes" << endl;
    else cout<<"No" << endl;
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