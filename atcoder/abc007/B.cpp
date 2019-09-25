#include <bits/stdc++.h>

using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (s.size() == 1 and s[0] == 'a')
        return cout << -1, 0;
    bool flag = false;
    for(auto &x : s){
        if(x > 'a')
            x-- , flag = true;
    }
    if(flag)
        cout << s;
    else
        cout <<s.substr(0 , s.size() - 1);
}