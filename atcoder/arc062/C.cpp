#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    pair<int, int> init = {1, 1};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        //ax >= init and bx >= init
        int newX = max(init.first/a + (init.first % a > 0), init.second/b + (init.second % b > 0));
        init = {a * newX, b * newX};
    }
    cout << init.first + init.second << endl;
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