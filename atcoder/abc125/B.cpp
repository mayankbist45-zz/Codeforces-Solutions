
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector< pair<int,int>> v(n);
    for (int i = 0; i < n; ++i)
        cin>>v[i].first;
    for (int i = 0; i < n; ++i)
        cin>>v[i].second;

    ll ans =0;
    for(auto x:v){
        if(x.first > x.second)
            ans += x.first - x.second;
    }
    cout<<ans;



    return 0;
}