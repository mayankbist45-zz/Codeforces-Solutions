
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

    string s;
    while (n != 0) {
        int rem = n % (-2);
        n = n / (-2);
        if (rem < 0) {
            rem = rem + 2;
            n = n + 1;
        }
        s.push_back('0' + rem);
    }
    reverse(s.begin(), s.end());
  	if(s.empty())
      s.push_back('0');
    cout << s << endl;
}
