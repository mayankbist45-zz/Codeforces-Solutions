#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a == b)cout << 0;
    else if(a < b){
        if(a % 2 != b % 2)cout << 1;
        else cout << 2;
    }
    else {
        if(a % 2 != b % 2)cout << 2;
        else cout << 1;
    }
    cout<< endl;
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