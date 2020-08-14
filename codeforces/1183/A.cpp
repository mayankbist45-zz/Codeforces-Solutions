#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int sum(int a){
    int cur = 0;
    while (a > 0)cur += a % 10, a /= 10;
    return cur;
}
void solve() {
    int a;
    cin >> a;

    int tp = sum(a);
    while(tp % 4 != 0){
        a++;
        tp = sum(a);
    }
    cout << a << endl;
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