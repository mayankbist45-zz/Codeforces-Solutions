#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
using int32 = __uint32_t;

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    vector<string> b, ea, rest, op;

    int ct = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i].front() == 'B' and v[i].back() == 'A')op.push_back(v[i]);
        else if (v[i].front() == 'B')b.push_back(v[i]);
        else if (v[i].back() == 'A')ea.push_back(v[i]);
        else rest.push_back(v[i]);
        for(int j = 0; j + 1 < v[i].size(); j++){
            if(v[i].substr(j, 2) == "AB")ct++;
        }
    }

    if(ea.size() + b.size() == 0 and op.size())ct += op.size() - 1;
    else if(op.size() == 0)ct += min(ea.size(), b.size());
    else if(op.size() and ea.size() + b.size() > 0)ct += op.size() +  min(ea.size(), b.size());
    
    cout << ct;
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
