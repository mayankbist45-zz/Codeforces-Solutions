#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sort(v[i].begin(), v[i].end());

        mp[v[i]]++;
    }
    int ans = 0;
    for(auto x: mp){
        if(x.second - 1 > 0){
            ans += x.second *(x.second - 1)/2 ;
        }
    }
    cout<< ans << endl;

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