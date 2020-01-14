#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, int> mp;
    map<int, int> isAc;
    int cr = 0, p = 0;
    for (int i = 0; i < m; i++) {
        int a;
        string b;
        cin >> a >> b;

        if (b == "AC" and isAc[a] == 0) {
            isAc[a] = 1;
            cr++;
            p += mp[a];
            mp[a] = 0;
        } else {
            if (isAc[a] == 0) {
                mp[a]++;
            }
        }
    }
    cout << cr << " " << p << endl;
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