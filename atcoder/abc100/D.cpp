#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct pot {
    int a, b, c;
};

int sa = 1, sb = 1, sc = 1;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pot> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }

    int ans = 0;
    for (int bit = 0; bit < 8; bit++) {
        if (bit & (1 << 0))sa = -1;
        else sa = 1;
        if (bit & (1 << 1))sb = -1;
        else sb = 1;
        if (bit & (1 << 2))sc = -1;
        else sc = 1;
        sort(v.begin(), v.end(), [](pot a, pot b) {
            return a.a * sa + a.b * sb + a.c * sc > b.a * sa + b.b * sb + b.c * sc;
        });
        int pa = 0, pb = 0, pc = 0;
        for (int i = 0; i < m; i++) {
            pa += v[i].a * sa;
            pb += v[i].b * sa;
            pc += v[i].c * sa;
        }
        ans = max(ans, abs(pa) + abs(pb) + abs(pc));
    }
    cout << ans << endl;
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