#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b)for (int i = 0; i < b; i++)cout << a;
    else if (a > b)for (int i = 0; i < a; i++)cout << b;
    else for (int i = 0; i < min(a, b); i++)cout << a;
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