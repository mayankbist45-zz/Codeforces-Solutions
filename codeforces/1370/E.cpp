#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int one = 0, zero = 0;
    for (int i = 0; i < a.size(); i++) {
        one += a[i] == '1';
        one -= b[i] == '1';
        zero += a[i] == '0';
        zero -= b[i] == '0';
    }
    if (one or zero) {
        cout << -1 << endl;
        return;
    }
    one = 0, zero = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])continue;
        if (a[i] == '0') {
            zero++;
            if (one)one--;
        } else {
            one++;
            if (zero)zero--;
        }
    }
    cout << one + zero << endl;
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