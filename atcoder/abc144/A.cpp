#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a , b;
    cin >> a >> b;

    if(a < 10 and b < 10)
        cout << a * b;
    else
        cout << -1;
}