#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

int v[maxn], sum = 0;

void add(int i, int x) {
    sum -= max(0ll, v[i]);
    v[i] += x;
    sum += max(v[i], 0ll);
}

void print() {
    int ans = ceil(double(sum + v[1]) / 2.0);
    cout << ans << endl;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 2; i <= n; i++)sum += max(0ll, v[i] - v[i - 1]);
    for (int i = n; i >= 2; i--)v[i] = v[i] - v[i - 1];
    print();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        if (l == 1)v[1] += x;
        else add(l, x);
        if (r + 1 <= n)
            add(r + 1, -x);
        print();
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