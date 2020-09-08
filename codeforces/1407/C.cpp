#include <bits/stdc++.h>

using namespace std;

#define int long long
#define maxn 100010
const int MOD = 1000000007;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ret;
    cin >> ret;
    return ret;
}

void print(vector<int> &ans) {
    cout << "! ";
    for (auto x: ans)cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<int> ans(n);
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        int a = query(cur, i);
        int b = query(i, cur);

        //cur % i > i % cur iff i < cur
        if (a > b) {
            ans[cur - 1] = a;
            cur = i;
        }
        else ans[i - 1] = b;
    }
    ans[cur - 1] = n;
    print(ans);
}

int32_t main() {
    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}