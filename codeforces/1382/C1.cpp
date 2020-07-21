#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void doit(string &a, int p) {
    for (int i = 0; i <= p; i++)
        if (a[i] == '1')a[i] = '0';
        else a[i] = '1';
    int i = 0, j = p;
    while (i <= j)
        swap(a[i++], a[j--]);
}

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> ans;
    for (int i = (int) a.size() - 1; i >= 0; i--) {
        if (a[i] == b[i])
            continue;
        if (a[i] != a[0])
            ans.push_back(0), doit(a, 0);
        ans.push_back(i);
        doit(a, i);
    }

    cout << ans.size() << " ";
    for (auto x: ans) cout << x + 1 << " ";
    cout << endl;

//    cout << a << " " << b << endl;
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