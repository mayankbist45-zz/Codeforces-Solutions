#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    int n, W;
    scanf("%d%d", &n, &W);
    vector<ll> dp(W + 1); // 0 ... W

    // dp[i] - the maximum total value of items with total weight exactly i
    for (int item = 0; item < n; ++item) {
        int weight, value;
        scanf("%d%d", &weight, &value);

        // dp[0] -> dp[3] -> dp[6]
        for (int weight_already = W - weight; weight_already >= 0; --weight_already) {

//        for(int weight_already = 0; weight_already <= W - weight; ++weight_already) {
            dp[weight_already + weight] = max(dp[weight_already + weight], dp[weight_already] + value);
        }
    }
    cout <<dp[W];
}
#pragma clang diagnostic pop