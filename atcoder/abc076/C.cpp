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
    string a, b;
    cin >> a >> b;

    auto check = [](const string a,const string b)->bool{
        if(a.size() != b.size())return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i] and a[i] != '?')return false;
        }
        return true;
    };
    int sz = b.size();
    int id = -1;
    for(int i = 0; i < a.size(); i++){
        bool fl = true;
        if(!check(a.substr(i, b.size()),b))fl = false;
        if(fl)
            id = i;
    }
    if(id == -1 or a.size() < b.size())cout << "UNRESTORABLE";
    else{
        for(int i = 0; i < a.size();i++){
            if(i == id){
                cout<< b;
                i+= b.size() - 1;
                continue;
            }
            else if(a[i] == '?')cout << 'a';
            else cout << a[i];
        }
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
