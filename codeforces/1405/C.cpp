#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ct1 = 0, ct2 = 0;

    for (int i = 0; i < k; i++) {

        int dgt = -1;

        for (int j = i; j < n; j += k)
            if (isdigit(s[j])) {
                if (dgt == -1)dgt = s[j] - '0';
                else if (dgt != s[j] - '0') {
                    cout << "NO" << endl;
                    return;
                }
            }
        if (dgt != -1)for (int j = i; j < n; j += k)s[j] = dgt + '0';
    }
    for (int i = 0; i < k; i++) {
        ct1 += s[i] == '0';
        ct2 += s[i] == '1';
    }
    if(max(ct1, ct2) > k/2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();
    return 0;
}