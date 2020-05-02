#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    double avg = (sum * 1.0) / (n * 1.0);
    double diff = 1e10;
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (diff > abs(v[i] - avg)) {
            diff = abs(v[i] - avg);
            id = i;
        }
    }
    cout << id << endl;
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
