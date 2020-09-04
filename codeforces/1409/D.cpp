#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, s;
    cin >> n >> s;

    string tp = to_string(n);
    int sum = 0;
    for (auto x: tp)sum += x - '0';
    reverse(tp.begin(), tp.end());
    int ct = 0, pos = 0, ten = 1;
    while (sum > s) {
        int cur = tp[pos] - '0';
        if (pos)
            cur += 1;
        int val = 10 - cur;
        ct += val * ten;
        sum -= cur;
        sum++;
        pos++;
        ten *= 10;
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