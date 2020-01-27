#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int h, a;
    cin >> h >> a;

    int sum = 0;
    for (int i = 0; i < a; i++) {
        int tp;
        cin >> tp;

        sum += tp;
    }
    if (sum >= h)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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