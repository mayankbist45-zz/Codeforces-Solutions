#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {

    string s, t;
    cin >> s >> t;

    int a = s.size();
    int b = t.size();

    int dp[a + 1][b + 1] = {};

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
//    cout << dp[a][b];

    int i = a , j = b;
    string ans;
    while(i>0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

