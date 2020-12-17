#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    string t;
    cin >> t;

    if (t == "1") {
        int val = 1e10 * 2;
        cout << val << endl;
        return;
    }

    if (t.front() != '1')t = '1' + t;
    if (t.front() == '1' and t.size() > 1 and t[1] == '0')t = '1' + t;

    if (t.back() != '0') {
        if (t.size() > 1 and t[t.size() - 2] != '1')t += "10";
        else if (t.size() == 1)t += "10";
        else t += '0';
    }


    for (int i = 0; i < t.size(); i += 3) {
        if (t.substr(i, 3) != "110") {
            cout << 0 << endl;
            return;
        }
    }
    int sz = 1e10 * 3 - t.size();
    cout << sz / 3 + 1 << endl;
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