#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

vector<int> p = {6, 10, 14, 15, 21};

void solve() {
    int n;
    cin >> n;

    if (n <= 30)cout << "NO" << endl;
    else {
        for (int i = 0; i < p.size(); i++)
            for (int j = i + 1; j < p.size(); ++j) {
                for (int k = j + 1; k < p.size(); ++k) {
                    if (p[i] + p[j] + p[k] < n) {
                        int re = n - (p[i] + p[j] + p[k]);
                        if (re != p[i] and re != p[j] and re != p[k]) {
                            cout << "YES" << endl;
                            cout << p[i] << " " << p[j] << " " << p[k] << " " << re << endl;
                            return;
                        }
                    }
                }
            }
        cout << "NO" << endl;
    }
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