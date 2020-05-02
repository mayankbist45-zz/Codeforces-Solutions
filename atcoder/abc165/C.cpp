#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

struct pot {
    int a, b, c, d;
};

vector<vector<int>> arr;

int n, m, q;

void generate(int pos, vector<int> v, int last) {
    if (pos == n) {
        arr.push_back(v);
        return;
    }
    for (int i = last; i <= m; i++) {
        v.push_back(i);
        generate(pos + 1, v, i);
        v.pop_back();
    }
}

void solve() {
    cin >> n >> m >> q;

    vector<pot> v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;

    vector<int> tp;
    int ans = 0;
    generate(0, tp, 1);
    for (auto &x : arr) {
        int pans = 0;
        for (auto &j : v) {
            if (x[j.b - 1] - x[j.a - 1] == j.c)pans += j.d;
        }
        ans = max(ans, pans);
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