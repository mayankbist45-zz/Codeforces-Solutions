#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "bits/stdc++.h"

using namespace std;

using ll = long long;
#define INF 1e18 + 5

int main() {
    int n, W;
    cin>>n>>W;

    vector<int> value(n),weight(n);
    int sum_values = 0;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
        sum_values += value[i];
    }
    vector<ll> dp(sum_values+1,INF);

    dp[0] = 0;
    for(int items = 0 ;items < n; items++){
        for(int value_already = sum_values - value[items]; value_already >= 0; value_already--){
            dp[value_already + value[items]] = min(dp[value_already + value[items]], weight[items] + dp[value_already]);
        }
    }
    ll ans = 0;
    for(int i=0;i<=sum_values;i++){
        if(dp[i] <= W)
            ans = max(ans,(ll)i);
    }
    cout<<ans;
}
#pragma clang diagnostic pop