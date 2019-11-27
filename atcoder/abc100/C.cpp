#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        while (v[i] % 2 == 0) {
            ans++;
            v[i] /= 2;
        }
    }
    cout << ans << endl;
}