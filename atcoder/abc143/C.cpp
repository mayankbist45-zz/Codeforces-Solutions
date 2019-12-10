//When nothing comes in mind gcd laga lena
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    char cur = '%';
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != cur) {
            ans++;
            cur = s[i];
        }
    }
    cout << ans << endl;
    return 0;
}