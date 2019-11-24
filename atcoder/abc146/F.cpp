#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int now = n;

    vector<int> ans;
    while (now > 0) {
        bool fl = false;
        for (int i = max(0ll , now - m); i < now; i++) {
            if (s[i] == '0') {
                ans.push_back(now - i);
                now = i;
                fl = true;
                break;
            }
        }
        if (!fl)
            break;
    }
    if (now)
        cout << -1 << endl;
    else
        for(int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
}