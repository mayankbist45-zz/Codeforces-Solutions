//20
//1 17 20 18 12 8 13 16 7 19 3 6 15 10 14 9 5 4 11 2

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int par = 1, ct = 0;
    for (int i = 1; i < n; i++) {
        int now = i, coutn = 0;
        for (int k = 0; k < par and now < n; k++) {
            int j = now;
            while (j + 1 < n and v[j + 1] > v[j])j++;
            int cur = j - now + 1;
            coutn += cur;
            now = j + 1;
        }
        par = coutn;
        ct++;
        i = now - 1;
    }
    cout << ct << endl;
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