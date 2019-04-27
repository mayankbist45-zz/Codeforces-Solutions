
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int ar[n][3];
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <3; ++j) {
            cin>>ar[i][j];
        }
    }

    for(int i = n-2;i>=0;i--){
        for(int j=0;j<3;j++){
            int ans =0 ;
            for(int k =0;k<3;k++){
                if(k!=j)
                 ans = max(ans,ar[i+1][k]);
            }
                ar[i][j] += ans;
        }
    }
    cout<<*max_element(ar[0],ar[0]+3);


    return 0;
}