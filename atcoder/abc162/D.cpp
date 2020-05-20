#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

char getOther(char ch) {
    for (auto x: {'R', 'G', 'B'})
        if (x != ch)return x;
}

char gett(char ch, char ch1) {
    for (auto x: {'R', 'G', 'B'})
        if (x != ch and x != ch1)return x;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, ordered_set > mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        char next = getOther(s[i]);
        char nn = gett(cur, next);
        for (auto x:mp[next]) {
            int id = i - x;
            int fd = (i - 2 * x) * -1;
            int del = 0;
            if (mp[nn].find(fd) != mp[nn].end())del = -1;

            ans += mp[nn].order_of_key(x) + del;
        }
        swap(nn, next);
        for (auto x:mp[next]) {
            int id = i - x;
            int fd = (i - 2 * x) * -1;
            int del = 0;
            if (mp[nn].find(fd) != mp[nn].end())del = -1;

            ans += mp[nn].order_of_key(x) + del;
        }
        mp[s[i]].insert(i);
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