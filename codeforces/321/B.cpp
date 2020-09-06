#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> val, def, cd;

int onlyAttacks() {
    sort(val.begin(), val.end());
    sort(cd.rbegin(), cd.rend());

    int ans = 0, add = 0;
    for (int i = 0; i < min(val.size(), cd.size()); i++) {
        if (cd[i] >= val[i])ans += cd[i] - val[i];
        else add++;
    }
    return ans;
}

int everything() {
    vector<int> vis(cd.size());
    sort(cd.begin(), cd.end());
    sort(def.begin(), def.end());
    sort(val.begin(), val.end());

    if (cd.size() < val.size() + def.size())return 0;
    int id = 0, done = 0;
    for (int i = 0; i < def.size() and id < cd.size(); i++) {
        while (id < cd.size() and def[i] >= cd[id])id++;
        if (id == cd.size())break;
        vis[id] = 1;
        id++, done++;
    }
    if (done != def.size())return 0;
    vector<int> some;
    for (int i = 0; i < cd.size(); i++)if (!vis[i])some.push_back(cd[i]);
    sort(some.begin(), some.end());
    id = 0, done = 0;
    for (int i = 0; i < val.size(); i++) {
        while (id < some.size() and val[i] > some[id])id++;
        if (id == some.size())return 0;
        id++, done++;
    }
    if(done != val.size())return 0;
    return accumulate(some.begin(), some.end(), 0ll) - accumulate(val.begin(), val.end(), 0ll);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int tp;
        cin >> tp;
        if (s[0] == 'A')val.push_back(tp);
        else def.push_back(tp);
    }
    cd = vector<int>(m);
    for (int i = 0; i < m; ++i) cin >> cd[i];
    cout << max(everything(), onlyAttacks()) << endl;
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