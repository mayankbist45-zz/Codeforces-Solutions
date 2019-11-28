#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' and k != i + 1)
            continue;
        return cout << s[i] << endl , 0;
    }
}