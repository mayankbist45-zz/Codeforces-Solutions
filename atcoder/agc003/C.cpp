#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

/*
 * 3 2 5 1 4 6
 */
bool same(int a, int b){
    return (a & 1) == (b & 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v, b;
    map<int, int> id;
    for (int i = 0, tp; i < n; i++) {
        cin >> tp;
        id[tp] = i;
        v.push_back(tp);
        b.push_back(tp);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i+=2) {
        if (id[b[i]] == i)continue;
        if (same(id[b[i]], i))continue;
        ans++;
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