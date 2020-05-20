#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define maxn 100010
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= 9; i++)dq.push_back(i);
    int ct = 0;
    while (ct < n) {
        int top = dq.front();
        dq.pop_front();
        ct++;
        if (ct == n) {
            cout << top << endl;
            return;
        }
        if (top % 10 != 0)dq.push_back(top * 10 + top % 10 - 1);
        dq.push_back(top * 10 + top % 10);
        if (top % 10 != 9)dq.push_back(top * 10 + top % 10 + 1);
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