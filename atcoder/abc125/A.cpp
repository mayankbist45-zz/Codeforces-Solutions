
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double t;
    int a,b;

    cin>>a>>b>>t;

    t += 0.5;

    int x = 0,ans = 0;
    while(true){
        x += a;
        if(x<=t)
         ans += b;
        else 
            break;
    }

    cout<<ans;
    return 0;
}