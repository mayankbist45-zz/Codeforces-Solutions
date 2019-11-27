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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] -= i + 1;
    }
    sort(v.begin(), v.end());
    int b = v[n / 2], ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += abs(v[j] - b);
    }
    cout << ans << endl;
}
