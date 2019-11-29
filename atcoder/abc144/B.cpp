#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i < 10 and n / i < 10)
                return cout << "Yes", 0;
        }
    }
    cout << "No" << endl;
}