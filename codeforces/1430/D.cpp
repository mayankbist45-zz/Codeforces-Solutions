#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    vector<int> len, id;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n and s[j + 1] == s[i])j++;
        len.push_back(j - i + 1);
        i = j;
    }
    for (int i = (int) len.size() - 1; i >= 0; i--)if (len.at(i) > 1)id.push_back(i);
    int lo = 0;
    while (lo < len.size()) {
        if (id.empty()) {
            ans += ((int) len.size() - lo + 1) / 2;
            break;
        } else {
            ans++;
            int val = id.back();
            id.pop_back();
            len[val]--;
            lo++;
            if (val >= lo and len[val] > 1)id.push_back(val);
        }
    }
    cout << ans << endl;
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