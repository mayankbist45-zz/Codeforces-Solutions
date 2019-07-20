#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    d = 2 * d + 1;
    cout << ceil(1.0 * n / d) ;
    return 0;
}
