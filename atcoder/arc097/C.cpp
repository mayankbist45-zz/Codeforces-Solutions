#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    set<string> v;
    for (int i = 0; i < s.size(); i++)
        for (int j = i; j >= 0 and i - j + 1 <= k; j--)
            v.insert(s.substr(j, i - j + 1));
    for (int i = 0; i < k - 1; i++)
        v.erase(v.begin());
    cout << *v.begin() << endl;
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