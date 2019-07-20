#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    int mx1 = -1, mx2 = -1;
    for(int i = 0 ; i < n ; i++) {
        cin >> v[i];
        if(v[i] >= mx1)mx2 = mx1 , mx1 = v[i];
        else if(v[i] > mx2)mx2 = v[i];
    }

    for(int i = 0 ; i < n ;i++)
        if(v[i] == mx1)
            cout << mx2 << endl ;
        else
            cout << mx1 << endl;

    return 0;
}