#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= 3500; i++)
        for (int j = i; j <= 3500; j++) {
            int a = i, b = j;
            int num = n * a * b;
            int deno = 4 * a * b - n * a - n * b;
            if (deno and num % deno == 0 and num / deno > 0) {
                cout << a << " " << b << " " << num/deno << endl;
                return;
            }
        }
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