#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string t = s;
    for (int i = k; i < n; i++) t[i] = t[i - k];
    if (t >= s)
        cout << s.size() << endl << t << endl;
    else {
        int ind = k;
        for (int i = k - 1; i >= 0; i--) {
            if (s[i] != '9') {
                ind = i + 1;
                s[i] += 1;
                break;
            }
        }

        for (int i = ind; i < k; i++)
            s[i] = '0';
        for (int i = k; i < n; i++) {
            s[i] = s[i - k];
        }
        cout << s.size() << endl;
        cout << s << endl;
    }
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