#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    string have[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<string> v;
    for (auto x: have) {
        v.push_back(string(n, x[0]) + string(n, x[1]) + string(n, x[2]));
        string psh;
        for (int i = 0; i < n; i++)psh += x;
        v.push_back(psh);
    }
    for (auto x: v) {
        if (x.find(a) == string::npos and x.find(b) == string::npos) {
            cout << "YES" << endl << x << endl;
            return;
        }
    }
    cout << "NO" << endl;
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