#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "Deficient\n";
        return;
    }

    int add = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            add += i;
            if (n / i != i and i != 1) {
                add += n / i;
            }
        }
    }
    if (add == n)
        cout << "Perfect";
    else if (add < n)
        cout << "Deficient";
    else
        cout << "Abundant";
    cout << endl;
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