#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 110
const int MOD = 1000000007;

int pref[maxn];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = " " + s;
    int a = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(')a++;
        else a--;
        if (a < 0)
            pref[0]++, a = 0;
    }
    a = 0;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            if (pref[i])
                for (int j = 0; j < pref[i]; j++)cout << "(" , a++;
            continue;
        }
        cout << s[i];
        if (s[i] == '(')a++;
        else a--;
    }
    for (int i = 0; i < a; i++)
        cout << ")";
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