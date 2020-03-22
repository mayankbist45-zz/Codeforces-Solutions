#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;
string s;

bool isPalin(int a, int b) {
    while (a < b) {
        if (s[a] != s[b])
            return false;
        a++, b--;
    }
    return true;
}

void solve() {
    cin >> s;
    if (isPalin(0, s.size() - 1) and isPalin(0, (s.size() - 1) / 2 - 1) and isPalin((s.size() + 3) / 2 - 1, s.size() - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}