#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int pw(int a, int b) {
    if (b == 0)
        return 1;
    if (b & 1)return a * pw(a, b - 1);
    return pw(a * a, b / 2);
}

void solve() {
    int n, k;
    cin >> n >> k;

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
        if (i % k == 0)a++;
        else if (i % k == k / 2)b++;
    if (k & 1)cout << pw(a, 3) << endl;
    else cout << pw(a, 3)+pw(b,3) << endl;
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