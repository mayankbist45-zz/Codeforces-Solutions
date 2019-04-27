
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int ar[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>ar[i];
    }

    vector<int> dp(n,INFINITY);
    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+k;j++)
            if(j<n)
                dp[j] = min(dp[j], dp[i]+abs(ar[i]-ar[j]));
    }
    cout<<dp[n-1];

    return 0;
}