#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 200010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    auto isValley = [&](int id) -> bool {
        if (id - 1 < 0 or id + 1 >= n)return false;
        return v[id] < v[id - 1] and v[id] < v[id + 1];
    };
    auto isHill = [&](int id) -> bool {
        if (id - 1 < 0 or id + 1 >= n)return false;
        return v[id] > v[id - 1] and v[id] > v[id + 1];
    };


    int mx = 0, ct = 0;
    for (int i = 1; i + 1 < n; i++) {
        int val = 0;
        ct += isValley(i) || isHill(i);
        if (isValley(i - 1) or isHill(i - 1))val++;
        if (isValley(i + 1) or isHill(i + 1))val++;
        if (isValley(i) or isHill(i))val++;

        int tp = v[i];
        v[i] = v[i - 1];
        int val2 = 0;
        if (isValley(i - 1) or isHill(i - 1))val2++;
        if (isValley(i + 1) or isHill(i + 1))val2++;
        if (isValley(i) or isHill(i))val2++;

        mx = max(mx, val - val2);
        v[i] = v[i + 1];
        val2 = 0;
        if (isValley(i - 1) or isHill(i - 1))val2++;
        if (isValley(i + 1) or isHill(i + 1))val2++;
        if (isValley(i) or isHill(i))val2++;
        mx = max(mx, val - val2);

        v[i] = tp;
    }
    cout << max(0ll, ct - mx) << endl;
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