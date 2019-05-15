#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;

    vector<vector<ll> > dp(n, vector<ll>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
        }
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < 3; j++){
            ll a = 0;
            for(int k = 0;k <3; k++){
                if(k!=j)
                    a = max(a, dp[i+1][k]);
            }
            dp[i][j] += a;
        }
    }

    cout << *max_element(dp[0].begin(),dp[0].begin()+3);
}